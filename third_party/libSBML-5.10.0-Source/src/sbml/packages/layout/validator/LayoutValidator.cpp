/**
 * @file:   LayoutValidator.cpp
 * @brief:  Implementation of the LayoutValidator class
 * @author: Generated by autocreate code
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2014 jointly by the following organizations:
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 *     3. University of Heidelberg, Heidelberg, Germany
 * 
 * Copyright (C) 2009-2013 jointly by the following organizations:
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 *
 * Copyright (C) 2006-2008 by the California Institute of Technology,
 *     Pasadena, CA, USA 
 *
 * Copyright (C) 2002-2005 jointly by the following organizations:
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. Japan Science and Technology Agency, Japan
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution
 * and also available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 */
#include <sbml/validator/VConstraint.h>

#include <sbml/packages/layout/common/LayoutExtensionTypes.h>
#include <sbml/packages/layout/validator/LayoutValidator.h>
#include <sbml/SBMLReader.h>

	/** @cond doxygenLibsbmlInternal */

using namespace std;

	/** @endcond */


LIBSBML_CPP_NAMESPACE_BEGIN
#ifdef __cplusplus

//
// NOTE: ConstraintSet, ValidatorConstraints, and ValidatingVisitor used to
// be in separate .cpp and .h files, but in order to link under MSVC6 (the
// compiler doesn't instantiate templates (i.e. generate code), even when
// told explicitly to do so), the classes needed to be combined into a single
// file.
//


// ----------------------------------------------------------------------
// Apply<T> and ConstraintSet<T>
// ----------------------------------------------------------------------


/*
 * Applies a Constraint<T> to an SBML object of type T.
 */
template <typename T>
struct Apply : public unary_function<TConstraint<T>*, void>
{
  Apply (const Model& m, const T& o) : model(m), object(o) { }


  void operator() (TConstraint<T>* constraint)
  {
    constraint->check(model, object);
  }


  const Model& model;
  const T&     object;
};


template <typename T>
class ConstraintSet
{
public:

   ConstraintSet () { }
  ~ConstraintSet () { }


  /*
   * Adds a Constraint to this ConstraintSet.
   */
  void add (TConstraint<T>* c)
  {
    constraints.push_back(c);
  }

  /*
   * Applies all Constraints in this ConstraintSet to the given SBML object
   * of type T.  Constraint violations are logged to Validator.
   */
  void applyTo (const Model& model, const T& object)
  {
    for_each(constraints.begin(), constraints.end(), Apply<T>(model, object));
  }

  /*
   * @return true if this ConstraintSet is empty, false otherwise.
   */
  bool empty () const
  {
    return constraints.empty();
  }


protected:

  std::list< TConstraint<T>* > constraints;
};



// ----------------------------------------------------------------------




// ----------------------------------------------------------------------
// ValidatorConstraints
// ----------------------------------------------------------------------

/*
 * ValidatorConstraints maintain a separate list of constraints for each
 * SBML type.  This is done so that constraints may be applied efficiently
 * during the validation process.
 */
struct LayoutValidatorConstraints
{
  ConstraintSet<SBMLDocument>             mSBMLDocument;
  ConstraintSet<Model>                    mModel;
	ConstraintSet<BoundingBox>      mBoundingBox;
	ConstraintSet<CompartmentGlyph>      mCompartmentGlyph;
	ConstraintSet<CubicBezier>      mCubicBezier;
	ConstraintSet<Curve>      mCurve;
	ConstraintSet<Dimensions>      mDimensions;
	ConstraintSet<GraphicalObject>      mGraphicalObject;
	ConstraintSet<Layout>      mLayout;
	ConstraintSet<LineSegment>      mLineSegment;
	ConstraintSet<Point>      mPoint;
	ConstraintSet<ReactionGlyph>      mReactionGlyph;
	ConstraintSet<SpeciesGlyph>      mSpeciesGlyph;
	ConstraintSet<SpeciesReferenceGlyph>      mSpeciesReferenceGlyph;
	ConstraintSet<TextGlyph>      mTextGlyph;
	ConstraintSet<ReferenceGlyph>      mReferenceGlyph;
	ConstraintSet<GeneralGlyph>      mGeneralGlyph;
  map<VConstraint*,bool> ptrMap;

  ~LayoutValidatorConstraints ();
  void add (VConstraint* c);
};


/*
 * Deletes constraints (TConstraint(T>*) which are stored in lists
 * (ConstraintSet<T>) of this struct.
 * Since the same pointer values could be stored in different lists
 * (e.g., TConstraint<SimpleSpeciesReference>* is stored in both
 * ConstraintSet<SimpleSpeciesReference> and
 * ConstraintSet<ModifierSimpleSpeciesReference>), a pointer map is used for
 * avoiding segmentation fault caused by deleting the same pointer twice.
 */
LayoutValidatorConstraints::~LayoutValidatorConstraints ()
{
  map<VConstraint*,bool>::iterator it = ptrMap.begin();

  while(it != ptrMap.end())
  {
     if(it->second) delete it->first;
     ++it;
  }
}


/*
 * Adds the given Contraint to the appropriate ConstraintSet.
 */
void
LayoutValidatorConstraints::add (VConstraint* c)
{
  if (c == NULL) return;

  ptrMap.insert(pair<VConstraint*,bool>(c,true));

  if (dynamic_cast< TConstraint<SBMLDocument>* >(c) != NULL)
  {
    mSBMLDocument.add( static_cast< TConstraint<SBMLDocument>* >(c) );
    return;
  }

  if (dynamic_cast< TConstraint<Model>* >(c) != NULL)
  {
    mModel.add( static_cast< TConstraint<Model>* >(c) );
    return;
  }
	if (dynamic_cast< TConstraint<BoundingBox>* >(c) != NULL)
	{
		mBoundingBox.add( static_cast< TConstraint<BoundingBox>* >(c) );
		return;
	}

	if (dynamic_cast< TConstraint<CompartmentGlyph>* >(c) != NULL)
	{
		mCompartmentGlyph.add( static_cast< TConstraint<CompartmentGlyph>* >(c) );
		return;
	}

	if (dynamic_cast< TConstraint<CubicBezier>* >(c) != NULL)
	{
		mCubicBezier.add( static_cast< TConstraint<CubicBezier>* >(c) );
		return;
	}

	if (dynamic_cast< TConstraint<Curve>* >(c) != NULL)
	{
		mCurve.add( static_cast< TConstraint<Curve>* >(c) );
		return;
	}

	if (dynamic_cast< TConstraint<Dimensions>* >(c) != NULL)
	{
		mDimensions.add( static_cast< TConstraint<Dimensions>* >(c) );
		return;
	}

	if (dynamic_cast< TConstraint<GraphicalObject>* >(c) != NULL)
	{
		mGraphicalObject.add( static_cast< TConstraint<GraphicalObject>* >(c) );
		return;
	}

	if (dynamic_cast< TConstraint<Layout>* >(c) != NULL)
	{
		mLayout.add( static_cast< TConstraint<Layout>* >(c) );
		return;
	}

	if (dynamic_cast< TConstraint<LineSegment>* >(c) != NULL)
	{
		mLineSegment.add( static_cast< TConstraint<LineSegment>* >(c) );
		return;
	}

	if (dynamic_cast< TConstraint<Point>* >(c) != NULL)
	{
		mPoint.add( static_cast< TConstraint<Point>* >(c) );
		return;
	}

	if (dynamic_cast< TConstraint<ReactionGlyph>* >(c) != NULL)
	{
		mReactionGlyph.add( static_cast< TConstraint<ReactionGlyph>* >(c) );
		return;
	}

	if (dynamic_cast< TConstraint<SpeciesGlyph>* >(c) != NULL)
	{
		mSpeciesGlyph.add( static_cast< TConstraint<SpeciesGlyph>* >(c) );
		return;
	}

	if (dynamic_cast< TConstraint<SpeciesReferenceGlyph>* >(c) != NULL)
	{
		mSpeciesReferenceGlyph.add( static_cast< TConstraint<SpeciesReferenceGlyph>* >(c) );
		return;
	}

	if (dynamic_cast< TConstraint<TextGlyph>* >(c) != NULL)
	{
		mTextGlyph.add( static_cast< TConstraint<TextGlyph>* >(c) );
		return;
	}

	if (dynamic_cast< TConstraint<ReferenceGlyph>* >(c) != NULL)
	{
		mReferenceGlyph.add( static_cast< TConstraint<ReferenceGlyph>* >(c) );
		return;
	}

	if (dynamic_cast< TConstraint<GeneralGlyph>* >(c) != NULL)
	{
		mGeneralGlyph.add( static_cast< TConstraint<GeneralGlyph>* >(c) );
		return;
	}

}

// ----------------------------------------------------------------------




// ----------------------------------------------------------------------
// ValidatingVisitor
// ----------------------------------------------------------------------


/*
 * An SBMLVisitor visits each object in an SBML object tree, calling the
 * appropriate visit() method for the object visited.
 *
 * A ValidatingVisitor overrides each visit method to validate the given
 * SBML object.
 */
class LayoutValidatingVisitor: public SBMLVisitor
{
public:

  using SBMLVisitor::visit;
  LayoutValidatingVisitor (LayoutValidator& v, const Model& m) : v(v), m(m) { }
  virtual void visit (const Model &x)
  {
    v.mLayoutConstraints->mModel.applyTo(m, x);
  }

	bool visit (const BoundingBox &x)
	{
		v.mLayoutConstraints->mBoundingBox.applyTo(m, x);
		return !v.mLayoutConstraints->mBoundingBox.empty();
	}

	bool visit (const CompartmentGlyph &x)
	{
		v.mLayoutConstraints->mCompartmentGlyph.applyTo(m, x);
		return !v.mLayoutConstraints->mCompartmentGlyph.empty();
	}

	bool visit (const CubicBezier &x)
	{
		v.mLayoutConstraints->mCubicBezier.applyTo(m, x);
		return !v.mLayoutConstraints->mCubicBezier.empty();
	}

	bool visit (const Curve &x)
	{
		v.mLayoutConstraints->mCurve.applyTo(m, x);
		return !v.mLayoutConstraints->mCurve.empty();
	}

	bool visit (const Dimensions &x)
	{
		v.mLayoutConstraints->mDimensions.applyTo(m, x);
		return !v.mLayoutConstraints->mDimensions.empty();
	}

	bool visit (const GraphicalObject &x)
	{
		v.mLayoutConstraints->mGraphicalObject.applyTo(m, x);
		return !v.mLayoutConstraints->mGraphicalObject.empty();
	}

	bool visit (const Layout &x)
	{
		v.mLayoutConstraints->mLayout.applyTo(m, x);
		return !v.mLayoutConstraints->mLayout.empty();
	}

	bool visit (const LineSegment &x)
	{
		v.mLayoutConstraints->mLineSegment.applyTo(m, x);
		return !v.mLayoutConstraints->mLineSegment.empty();
	}

	bool visit (const Point &x)
	{
		v.mLayoutConstraints->mPoint.applyTo(m, x);
		return !v.mLayoutConstraints->mPoint.empty();
	}

	bool visit (const ReactionGlyph &x)
	{
		v.mLayoutConstraints->mReactionGlyph.applyTo(m, x);
		return !v.mLayoutConstraints->mReactionGlyph.empty();
	}

	bool visit (const SpeciesGlyph &x)
	{
		v.mLayoutConstraints->mSpeciesGlyph.applyTo(m, x);
		return !v.mLayoutConstraints->mSpeciesGlyph.empty();
	}

	bool visit (const SpeciesReferenceGlyph &x)
	{
		v.mLayoutConstraints->mSpeciesReferenceGlyph.applyTo(m, x);
		return !v.mLayoutConstraints->mSpeciesReferenceGlyph.empty();
	}

	bool visit (const TextGlyph &x)
	{
		v.mLayoutConstraints->mTextGlyph.applyTo(m, x);
		return !v.mLayoutConstraints->mTextGlyph.empty();
	}

	bool visit (const ReferenceGlyph &x)
	{
		v.mLayoutConstraints->mReferenceGlyph.applyTo(m, x);
		return !v.mLayoutConstraints->mReferenceGlyph.empty();
	}

	bool visit (const GeneralGlyph &x)
	{
		v.mLayoutConstraints->mGeneralGlyph.applyTo(m, x);
		return !v.mLayoutConstraints->mGeneralGlyph.empty();
	}

	virtual bool visit(const SBase &x)
	{
		if (&x == NULL || x.getPackageName() != "layout")
		{
			return SBMLVisitor::visit(x);
		}

		int code = x.getTypeCode();

		const ListOf* list = dynamic_cast<const ListOf*>(&x);

		if (list != NULL)
		{
			return SBMLVisitor::visit(x);
		}
		else
		{
			if (code == SBML_LAYOUT_BOUNDINGBOX)
			{
				return visit((const BoundingBox&)x);
			}
			else if (code == SBML_LAYOUT_COMPARTMENTGLYPH)
			{
				return visit((const CompartmentGlyph&)x);
			}
			else if (code == SBML_LAYOUT_CUBICBEZIER)
			{
				return visit((const CubicBezier&)x);
			}
			else if (code == SBML_LAYOUT_CURVE)
			{
				return visit((const Curve&)x);
			}
			else if (code == SBML_LAYOUT_DIMENSIONS)
			{
				return visit((const Dimensions&)x);
			}
			else if (code == SBML_LAYOUT_GRAPHICALOBJECT)
			{
				return visit((const GraphicalObject&)x);
			}
			else if (code == SBML_LAYOUT_LAYOUT)
			{
				return visit((const Layout&)x);
			}
			else if (code == SBML_LAYOUT_LINESEGMENT)
			{
				return visit((const LineSegment&)x);
			}
			else if (code == SBML_LAYOUT_POINT)
			{
				return visit((const Point&)x);
			}
			else if (code == SBML_LAYOUT_REACTIONGLYPH)
			{
				return visit((const ReactionGlyph&)x);
			}
			else if (code == SBML_LAYOUT_SPECIESGLYPH)
			{
				return visit((const SpeciesGlyph&)x);
			}
			else if (code == SBML_LAYOUT_SPECIESREFERENCEGLYPH)
			{
				return visit((const SpeciesReferenceGlyph&)x);
			}
			else if (code == SBML_LAYOUT_TEXTGLYPH)
			{
				return visit((const TextGlyph&)x);
			}
			else if (code == SBML_LAYOUT_REFERENCEGLYPH)
			{
				return visit((const ReferenceGlyph&)x);
			}
			else if (code == SBML_LAYOUT_GENERALGLYPH)
			{
				return visit((const GeneralGlyph&)x);
			}
      else 
      {
        return SBMLVisitor::visit(x);
      } 
    }
  }

protected:

  LayoutValidator&   v;
  const Model& m;
};


// ----------------------------------------------------------------------




// ----------------------------------------------------------------------
// Validator
// ----------------------------------------------------------------------


LayoutValidator::LayoutValidator (const SBMLErrorCategory_t category):
  Validator(category)
{
  mLayoutConstraints = new LayoutValidatorConstraints();
}


LayoutValidator::~LayoutValidator ()
{
  delete mLayoutConstraints;
}


/*
 * Adds the given Contraint to this validator.
 */
void
LayoutValidator::addConstraint (VConstraint* c)
{
  mLayoutConstraints->add(c);
}


/*
 * Validates the given SBMLDocument.  Failures logged during
 * validation may be retrieved via <code>getFailures()</code>.
 *
 * @return the number of validation errors that occurred.
 */
unsigned int
LayoutValidator::validate (const SBMLDocument& d)
{
  if (&d == NULL) return 0;

  const Model* m = d.getModel();

  if (m != NULL)
  {
    const LayoutSBMLDocumentPlugin* docPlug = 
      static_cast <const LayoutSBMLDocumentPlugin *> (d.getPlugin("layout"));

    if (docPlug != NULL
      && docPlug->haveValidationListsBeenPopulated() == false)
    {
      const_cast<LayoutSBMLDocumentPlugin *>(docPlug)->populateValidationLists();
    }


    LayoutValidatingVisitor vv(*this, *m);

    const LayoutModelPlugin* plugin = 
      static_cast <const LayoutModelPlugin *> (m->getPlugin("layout"));
      
    if (plugin != NULL)
    {
      plugin->accept(vv);
    }
  }

  /* ADD ANY OTHER OBJECTS THAT HAVE PLUGINS */
  
  return (unsigned int)mFailures.size();
}


/*
 * Validates the given SBMLDocument.  Failures logged during
 * validation may be retrieved via <code>getFailures()</code>.
 *
 * @return the number of validation errors that occurred.
 */
unsigned int
LayoutValidator::validate (const std::string& filename)
{
  if (&filename == NULL) return 0;

  SBMLReader    reader;
  SBMLDocument& d = *reader.readSBML(filename);


  for (unsigned int n = 0; n < d.getNumErrors(); ++n)
  {
    logFailure( *d.getError(n) );
  }

  return validate(d);
}


#endif /* __cplusplus */
LIBSBML_CPP_NAMESPACE_END

// ----------------------------------------------------------------------
