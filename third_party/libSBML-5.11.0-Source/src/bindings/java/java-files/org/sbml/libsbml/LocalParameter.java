/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.4
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package org.sbml.libsbml;

/** 
 *  A parameter inside an SBML <em>reaction</em> definition.
 <p>
 * {@link LocalParameter} has been introduced in SBML Level&nbsp;3 to serve as the
 * object class for parameter definitions that are intended to be local to
 * a {@link Reaction}.  Objects of class {@link LocalParameter} never appear at the {@link Model}
 * level; they are always contained within {@link ListOfLocalParameters} lists
 * which are in turn contained within {@link KineticLaw} objects.
 <p>
 * Like its global {@link Parameter} counterpart, the {@link LocalParameter} object class
 * is used to define a symbol associated with a value; this symbol can then
 * be used in a model's mathematical formulas (and specifically, for
 * {@link LocalParameter}, reaction rate formulas).  Unlike {@link Parameter}, the
 * {@link LocalParameter} class does not have a 'constant' attribute: local
 * parameters within reactions are <em>always</em> constant.
 <p>
 * {@link LocalParameter} has one required attribute, 'id', to give the
 * parameter a unique identifier by which other parts of an SBML model
 * definition can refer to it.  A parameter can also have an optional
 * 'name' attribute of type <code>string.</code>  Identifiers and names must be used
 * according to the guidelines described in the SBML specifications.
 <p>
 * The optional attribute 'value' determines the value (of type <code>double</code>)
 * assigned to the parameter.  A missing value for 'value' implies that
 * the value either is unknown, or to be obtained from an external source,
 * or determined by an initial assignment.  The unit of measurement
 * associated with the value of the parameter can be specified using the
 * optional attribute 'units'.  Here we only mention briefly some notable
 * points about the possible unit choices, but readers are urged to consult
 * the SBML specification documents for more information:
 * <ul>
 <p>
 * <li> In SBML Level&nbsp;3, there are no constraints on the units that
 * can be assigned to parameters in a model; there are also no units to
 * inherit from the enclosing {@link Model} object.
 <p>
 * <li> In SBML Level&nbsp;2, the value assigned to the parameter's 'units'
 * attribute must be chosen from one of the following possibilities: one of
 * the base unit identifiers defined in SBML; one of the built-in unit
 * identifiers <code>'substance'</code>, <code>'time'</code>, <code>'volume'</code>, <code>'area'</code> or 
 * <code>'length'</code>; or the identifier of a new unit defined in the list of unit
 * definitions in the enclosing {@link Model} structure.  There are no constraints
 * on the units that can be chosen from these sets.  There are no default
 * units for local parameters.
 * </ul>
 <p>
 * As with all other major SBML components, {@link LocalParameter} is derived from
 * {@link SBase}, and the methods defined on {@link SBase} are available on {@link LocalParameter}.
 <p>
 * @warning <span class='warning'>LibSBML derives {@link LocalParameter} from
 * {@link Parameter}; however, this does not precisely match the object hierarchy
 * defined by SBML Level&nbsp;3, where {@link LocalParameter} is derived directly
 * from {@link SBase} and not {@link Parameter}.  We believe this arrangement makes it easier
 * for libSBML users to program applications that work with both SBML
 * Level&nbsp;2 and SBML Level&nbsp;3, but programmers should also keep in
 * mind this difference exists.  A side-effect of libSBML's scheme is that
 * certain methods on {@link LocalParameter} that are inherited from {@link Parameter} do not
 * actually have relevance to {@link LocalParameter} objects.  An example of this is
 * the methods pertaining to {@link Parameter}'s attribute 'constant' (i.e.,
 * isSetConstant(), setConstant(), and getConstant()).</span>
 <p>
 * @see ListOfLocalParameters
 * @see KineticLaw
 */

public class LocalParameter extends Parameter {
   private long swigCPtr;

   protected LocalParameter(long cPtr, boolean cMemoryOwn)
   {
     super(libsbmlJNI.LocalParameter_SWIGUpcast(cPtr), cMemoryOwn);
     swigCPtr = cPtr;
   }

   protected static long getCPtr(LocalParameter obj)
   {
     return (obj == null) ? 0 : obj.swigCPtr;
   }

   protected static long getCPtrAndDisown (LocalParameter obj)
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
        libsbmlJNI.delete_LocalParameter(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  
/**
   * Creates a new {@link LocalParameter} object with the given SBML <code>level</code> and
   * <code>version</code> values.
   <p>
   * @param level a long integer, the SBML Level to assign to this
   * {@link LocalParameter}.
   <p>
   * @param version a long integer, the SBML Version to assign to this
   * {@link LocalParameter}.
   <p>
   * @throws SBMLConstructorException
   * Thrown if the given <code>level</code> and <code>version</code> combination, or this kind
   * of SBML object, are either invalid or mismatched with respect to the
   * parent {@link SBMLDocument} object.
   <p>
   * <p>
 * @note Attempting to add an object to an {@link SBMLDocument} having a different
 * combination of SBML Level, Version and XML namespaces than the object
 * itself will result in an error at the time a caller attempts to make the
 * addition.  A parent object must have compatible Level, Version and XML
 * namespaces.  (Strictly speaking, a parent may also have more XML
 * namespaces than a child, but the reverse is not permitted.)  The
 * restriction is necessary to ensure that an SBML model has a consistent
 * overall structure.  This requires callers to manage their objects
 * carefully, but the benefit is increased flexibility in how models can be
 * created by permitting callers to create objects bottom-up if desired.  In
 * situations where objects are not yet attached to parents (e.g.,
 * {@link SBMLDocument}), knowledge of the intented SBML Level and Version help
 * libSBML determine such things as whether it is valid to assign a
 * particular value to an attribute.
   */ public
 LocalParameter(long level, long version) throws org.sbml.libsbml.SBMLConstructorException {
    this(libsbmlJNI.new_LocalParameter__SWIG_0(level, version), true);
  }

  
/**
   * Creates a new {@link LocalParameter} object with the given {@link SBMLNamespaces}
   * object <code>sbmlns</code>.
   <p>
   * <p>
 * The {@link SBMLNamespaces} object encapsulates SBML Level/Version/namespaces
 * information.  It is used to communicate the SBML Level, Version, and (in
 * Level&nbsp;3) packages used in addition to SBML Level&nbsp;3 Core.  A
 * common approach to using libSBML's {@link SBMLNamespaces} facilities is to create an
 * {@link SBMLNamespaces} object somewhere in a program once, then hand that object
 * as needed to object constructors that accept {@link SBMLNamespaces} as arguments. 
   <p>
   * It is worth emphasizing that although this constructor does not take
   * an identifier argument, in SBML Level&nbsp;2 and beyond, the 'id'
   * (identifier) attribute of a {@link LocalParameter} is required to have a value.
   * Thus, callers are cautioned to assign a value after calling this
   * constructor if no identifier is provided as an argument.  Setting the
   * identifier can be accomplished using the method
   * setId(String id).
   <p>
   * @param sbmlns an {@link SBMLNamespaces} object.
   <p>
   * @throws SBMLConstructorException
   * Thrown if the given <code>level</code> and <code>version</code> combination, or this kind
   * of SBML object, are either invalid or mismatched with respect to the
   * parent {@link SBMLDocument} object.
   <p>
   * <p>
 * @note Attempting to add an object to an {@link SBMLDocument} having a different
 * combination of SBML Level, Version and XML namespaces than the object
 * itself will result in an error at the time a caller attempts to make the
 * addition.  A parent object must have compatible Level, Version and XML
 * namespaces.  (Strictly speaking, a parent may also have more XML
 * namespaces than a child, but the reverse is not permitted.)  The
 * restriction is necessary to ensure that an SBML model has a consistent
 * overall structure.  This requires callers to manage their objects
 * carefully, but the benefit is increased flexibility in how models can be
 * created by permitting callers to create objects bottom-up if desired.  In
 * situations where objects are not yet attached to parents (e.g.,
 * {@link SBMLDocument}), knowledge of the intented SBML Level and Version help
 * libSBML determine such things as whether it is valid to assign a
 * particular value to an attribute.
   */ public
 LocalParameter(SBMLNamespaces sbmlns) throws org.sbml.libsbml.SBMLConstructorException {
    this(libsbmlJNI.new_LocalParameter__SWIG_1(SBMLNamespaces.getCPtr(sbmlns), sbmlns), true);
  }

  
/**
   * Copy constructor; creates a copy of a given {@link LocalParameter} object.
   <p>
   * @param orig the {@link LocalParameter} instance to copy.
   <p>
   * @throws SBMLConstructorException
   * Thrown if the argument <code>orig</code> is <code>null.</code>
   */ public
 LocalParameter(LocalParameter orig) throws org.sbml.libsbml.SBMLConstructorException {
    this(libsbmlJNI.new_LocalParameter__SWIG_2(LocalParameter.getCPtr(orig), orig), true);
  }

  
/**
   * Copy constructor; creates a {@link LocalParameter} object by copying
   * the attributes of a given {@link Parameter} object.
   <p>
   * @param orig the {@link Parameter} instance to copy.
   <p>
   * @throws SBMLConstructorException
   * Thrown if the argument <code>orig</code> is <code>null.</code>
   */ public
 LocalParameter(Parameter orig) throws org.sbml.libsbml.SBMLConstructorException {
    this(libsbmlJNI.new_LocalParameter__SWIG_3(Parameter.getCPtr(orig), orig), true);
  }

  
/**
   * Creates and returns a deep copy of this {@link LocalParameter} object.
   <p>
   * @return the (deep) copy of this {@link LocalParameter} object.
   */ public
 LocalParameter cloneObject() {
    long cPtr = libsbmlJNI.LocalParameter_cloneObject(swigCPtr, this);
    return (cPtr == 0) ? null : new LocalParameter(cPtr, true);
  }

  
/**
   * Constructs and returns a {@link UnitDefinition} that corresponds to the units
   * of this {@link LocalParameter}'s value.
   <p>
   * <p>
 * LocalParameters in SBML have an attribute ('units') for declaring the
 * units of measurement intended for the parameter's value.  <b>No
 * defaults are defined</b> by SBML in the absence of a definition for
 * 'units'.  This method returns a {@link UnitDefinition} object based on the
 * units declared for this {@link LocalParameter} using its 'units' attribute, or
 * it returns <code>null</code> if no units have been declared.
 <p>
 * Note that unit declarations for {@link LocalParameter} objects are specified
 * in terms of the <em>identifier</em> of a unit (e.g., using setUnits()), but
 * <em>this</em> method returns a {@link UnitDefinition} object, not a unit
 * identifier.  It does this by constructing an appropriate
 * {@link UnitDefinition}.  For SBML Level&nbsp;2 models, it will do this even
 * when the value of the 'units' attribute is one of the predefined SBML
 * units <code>'substance'</code>, <code>'volume'</code>, <code>'area'</code>, <code>'length'</code> or 
 * <code>'time'.</code>  Callers may find this useful in conjunction with the helper
 * methods provided by the {@link UnitDefinition} class for comparing different
 * {@link UnitDefinition} objects.
   <p>
   * @return a {@link UnitDefinition} that expresses the units of this 
   * {@link LocalParameter}, or <code>null</code> if one cannot be constructed.
   <p>
   * @note The libSBML system for unit analysis depends on the model as a
   * whole.  In cases where the {@link LocalParameter} object has not yet been
   * added to a model, or the model itself is incomplete, unit analysis is
   * not possible, and consequently this method will return <code>null.</code>
   <p>
   * @see #isSetUnits()
   */ public
 UnitDefinition getDerivedUnitDefinition() {
    long cPtr = libsbmlJNI.LocalParameter_getDerivedUnitDefinition__SWIG_0(swigCPtr, this);
    return (cPtr == 0) ? null : new UnitDefinition(cPtr, false);
  }

  
/**
   * Returns the libSBML type code for this SBML object.
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
   * @return the SBML type code for this object:
   * {@link libsbmlConstants#SBML_LOCAL_PARAMETER SBML_LOCAL_PARAMETER} (default).
   <p>
   * <p>
 * @warning <span class='warning'>The specific integer values of the possible
 * type codes may be reused by different Level&nbsp;3 package plug-ins.
 * Thus, to identifiy the correct code, <strong>it is necessary to invoke
 * both getTypeCode() and getPackageName()</strong>.</span>
   <p>
   * @see #getElementName()
   * @see #getPackageName()
   */ public
 int getTypeCode() {
    return libsbmlJNI.LocalParameter_getTypeCode(swigCPtr, this);
  }

  
/**
   * Returns the XML element name of this object, which for {@link LocalParameter},
   * is always <code>'localParameter'.</code>
   <p>
   * @return the name of this element, i.e., <code>'localParameter'.</code>
   */ public
 String getElementName() {
    return libsbmlJNI.LocalParameter_getElementName(swigCPtr, this);
  }

  
/**
   * Predicate returning <code>true</code> if all the required attributes for this
   * {@link LocalParameter} object have been set.
   <p>
   * The required attributes for a {@link LocalParameter} object are:
   * <ul>
   * <li> 'id'
   * <li> 'value'
   *
   * </ul> <p>
   * @return <code>true</code> if the required attributes have been set, <code>false</code>
   * otherwise.
   */ public
 boolean hasRequiredAttributes() {
    return libsbmlJNI.LocalParameter_hasRequiredAttributes(swigCPtr, this);
  }

  
/** * @internal */ public
 boolean getConstant() {
    return libsbmlJNI.LocalParameter_getConstant(swigCPtr, this);
  }

  
/** * @internal */ public
 boolean isSetConstant() {
    return libsbmlJNI.LocalParameter_isSetConstant(swigCPtr, this);
  }

  
/** * @internal */ public
 int setConstant(boolean flag) {
    return libsbmlJNI.LocalParameter_setConstant(swigCPtr, this, flag);
  }

}
