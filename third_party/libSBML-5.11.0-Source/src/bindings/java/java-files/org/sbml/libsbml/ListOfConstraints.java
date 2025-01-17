/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.4
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package org.sbml.libsbml;

/** 
 *  A list of {@link Constraint} objects.
 <p>
 * <p>
 * The various ListOf___ classes in SBML
 * are merely containers used for organizing the main components of an SBML
 * model.  In libSBML's implementation, ListOf___
 * classes are derived from the
 * intermediate utility class {@link ListOf}, which
 * is not defined by the SBML specifications but serves as a useful
 * programmatic construct.  {@link ListOf} is itself is in turn derived from {@link SBase},
 * which provides all of the various ListOf___
 * classes with common features
 * defined by the SBML specification, such as 'metaid' attributes and
 * annotations.
 <p>
 * The relationship between the lists and the rest of an SBML model is
 * illustrated by the following (for SBML Level&nbsp;2 Version&nbsp;4):
 <p>
 * <figure>
  <object type="image/svg+xml" data="listof-illustration.svg" class="centered"></object>
</figure>

 <p>
 * Readers may wonder about the motivations for using the ListOf___
 * containers in SBML.  A simpler approach in XML might be to place the
 * components all directly at the top level of the model definition.  The
 * choice made in SBML is to group them within XML elements named after
 * ListOf<em>Classname</em>, in part because it helps organize the
 * components.  More importantly, the fact that the container classes are
 * derived from {@link SBase} means that software tools can add information <em>about</em>
 * the lists themselves into each list container's 'annotation'.
 <p>
 * @see ListOfFunctionDefinitions
 * @see ListOfUnitDefinitions
 * @see ListOfCompartmentTypes
 * @see ListOfSpeciesTypes
 * @see ListOfCompartments
 * @see ListOfSpecies
 * @see ListOfParameters
 * @see ListOfInitialAssignments
 * @see ListOfRules
 * @see ListOfConstraints
 * @see ListOfReactions
 * @see ListOfEvents
 */

public class ListOfConstraints extends ListOf {
   private long swigCPtr;

   protected ListOfConstraints(long cPtr, boolean cMemoryOwn)
   {
     super(libsbmlJNI.ListOfConstraints_SWIGUpcast(cPtr), cMemoryOwn);
     swigCPtr = cPtr;
   }

   protected static long getCPtr(ListOfConstraints obj)
   {
     return (obj == null) ? 0 : obj.swigCPtr;
   }

   protected static long getCPtrAndDisown (ListOfConstraints obj)
   {
     long ptr = 0;

     if (obj != null)
     {
       ptr             = obj.swigCPtr;
       obj.swigCMemOwn = false;
     }

     return ptr;
   }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        libsbmlJNI.delete_ListOfConstraints(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  
/**
   * Creates a new {@link ListOfConstraints} object.
   <p>
   * The object is constructed such that it is valid for the given SBML
   * Level and Version combination.
   <p>
   * @param level the SBML Level
   <p>
   * @param version the Version within the SBML Level
   */ public
 ListOfConstraints(long level, long version) throws org.sbml.libsbml.SBMLConstructorException {
    this(libsbmlJNI.new_ListOfConstraints__SWIG_0(level, version), true);
  }

  
/**
   * Creates a new {@link ListOfConstraints} object.
   <p>
   * The object is constructed such that it is valid for the SBML Level and
   * Version combination determined by the {@link SBMLNamespaces} object in 
   * <code>sbmlns</code>.
   <p>
   * @param sbmlns an {@link SBMLNamespaces} object that is used to determine the
   * characteristics of the {@link ListOfConstraints} object to be created.
   */ public
 ListOfConstraints(SBMLNamespaces sbmlns) throws org.sbml.libsbml.SBMLConstructorException {
    this(libsbmlJNI.new_ListOfConstraints__SWIG_1(SBMLNamespaces.getCPtr(sbmlns), sbmlns), true);
  }

  
/**
   * Creates and returns a deep copy of this {@link ListOfConstraints} object.
   <p>
   * @return the (deep) copy of this {@link ListOfConstraints} object.
   */ public
 ListOfConstraints cloneObject() {
    long cPtr = libsbmlJNI.ListOfConstraints_cloneObject(swigCPtr, this);
    return (cPtr == 0) ? null : new ListOfConstraints(cPtr, true);
  }

  
/**
   * Returns the libSBML type code for the objects contained in this {@link ListOf}
   * (i.e., {@link Constraint} objects, if the list is non-empty).
   <p>
   * <p>
 * LibSBML attaches an identifying code to every kind of SBML object.  These
 * are integer constants known as <em>SBML type codes</em>.  The names of all
 * the codes begin with the characters <code>SBML_</code>.
 * In the Java language interface for libSBML, the
 * type codes are defined as static integer constants in the interface class
 * {@link libsbmlConstants}.    Note that different Level&nbsp;3
 * package plug-ins may use overlapping type codes; to identify the package
 * to which a given object belongs, call the <code>getPackageName()</code>
 * method on the object.
   <p>
   * @return the SBML type code for the objects contained in this {@link ListOf}
   * instance: {@link libsbmlConstants#SBML_CONSTRAINT SBML_CONSTRAINT} (default).
   <p>
   * @see #getElementName()
   * @see #getPackageName()
   */ public
 int getItemTypeCode() {
    return libsbmlJNI.ListOfConstraints_getItemTypeCode(swigCPtr, this);
  }

  
/**
   * Returns the XML element name of this object.
   <p>
   * For {@link ListOfConstraints}, the XML element name is <code>'listOfConstraints'.</code>
   <p>
   * @return the name of this element.
   */ public
 String getElementName() {
    return libsbmlJNI.ListOfConstraints_getElementName(swigCPtr, this);
  }

  
/**
   * Get a {@link Constraint} from the {@link ListOfConstraints}.
   <p>
   * @param n the index number of the {@link Constraint} to get.
   <p>
   * @return the nth {@link Constraint} in this {@link ListOfConstraints}.
   <p>
   * @see #size()
   */ public
 Constraint get(long n) {
    long cPtr = libsbmlJNI.ListOfConstraints_get__SWIG_0(swigCPtr, this, n);
    return (cPtr == 0) ? null : new Constraint(cPtr, false);
  }

  
/**
   * Removes the nth item from this {@link ListOfConstraints} items and returns a
   * pointer to it.
   <p>
   * The caller owns the returned item and is responsible for deleting it.
   <p>
   * @param n the index of the item to remove
   <p>
   * @see #size()
   */ public
 Constraint remove(long n) {
    long cPtr = libsbmlJNI.ListOfConstraints_remove(swigCPtr, this, n);
    return (cPtr == 0) ? null : new Constraint(cPtr, true);
  }

}
