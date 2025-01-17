using System;
using System.Runtime.InteropServices;


/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.4
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

namespace libsbmlcs {

 using System;
 using System.Runtime.InteropServices;

/** 
 * @sbmlpackage{core}
 *
@htmlinclude pkg-marker-core.html An interface to an XML input stream.
 *
 * @htmlinclude not-sbml-warning.html
 *
 * SBML content is serialized using XML; the resulting data can be stored and
 * read to/from a file or data stream.  Low-level XML parsers such as Xerces
 * provide facilities to read XML data.  To permit the use of different XML
 * parsers (Xerces, Expat or libxml2), libSBML implements an abstraction
 * layer.  XMLInputStream and XMLOutputStream are two parts of that
 * abstraction layer.
 *
 * XMLInputStream is an interface to a file or text string containing XML.
 * It wraps the content to be read, as well as the low-level XML parser to be
 * used and an XMLErrorLog to record errors and other issues (if any arise).
 * Internally, the content will be in the form of either a pointer to a file
 * name or a character string; XMLInputStream knows the form of the content
 * and acts appropriately.  Other libSBML object classes use XMLInputStream
 * as their interface for all read operations on the XML data.
 * XMLInputStream provides the functionality to extract data in the form of
 * XMLToken objects.  It logs any errors encountered while reading.  It also
 * keeps track of whether a read operation has failed irrecoverably or
 * determines whether it is safe to continue reading.
 *
 * SBMLNamespaces objects can be associated with an XMLInputStream; this
 * facilitates logging errors related to reading XML attributes and elements
 * that may only be relevant to particular Level and Version combinations of
 * SBML.
 *
 * @note The convenience of the XMLInputStream and XMLOutputStream
 * abstraction may be useful for developers interested in creating parsers
 * for other XML formats besides SBML.  It can provide developers with a
 * layer above more basic XML parsers, as well as some useful programmatic
 * elements such as XMLToken, XMLError, etc.
 *
 * @see XMLOutputStream
 */

public class XMLInputStream : IDisposable {
	private HandleRef swigCPtr;
	protected bool swigCMemOwn;
	
	internal XMLInputStream(IntPtr cPtr, bool cMemoryOwn)
	{
		swigCMemOwn = cMemoryOwn;
		swigCPtr    = new HandleRef(this, cPtr);
	}
	
	internal static HandleRef getCPtr(XMLInputStream obj)
	{
		return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
	}
	
	internal static HandleRef getCPtrAndDisown (XMLInputStream obj)
	{
		HandleRef ptr = new HandleRef(null, IntPtr.Zero);
		
		if (obj != null)
		{
			ptr             = obj.swigCPtr;
			obj.swigCMemOwn = false;
		}
		
		return ptr;
	}

  ~XMLInputStream() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          libsbmlPINVOKE.delete_XMLInputStream(swigCPtr);
        }
        swigCPtr = new HandleRef(null, IntPtr.Zero);
      }
      GC.SuppressFinalize(this);
    }
  }

  
/**
   * Creates a new XMLInputStream.
   *
   * @param content the source of the stream.
   *
   * @param isFile a bool flag to indicate whether @p content is a file
   * name.  If @c true, @p content is assumed to be the file from which the
   * XML content is to be read.  If @c false, @p content is taken to be a
   * string that @em is the content to be read.
   *
   * @param library the name of the parser library to use.
   *
   * @param errorLog the XMLErrorLog object to use.
   *
   * @ifnot hasDefaultArgs @htmlinclude warn-default-args-in-docs.html @endif
   */ public
 XMLInputStream(string content, bool isFile, string library, XMLErrorLog errorLog) : this(libsbmlPINVOKE.new_XMLInputStream__SWIG_0(content, isFile, library, XMLErrorLog.getCPtr(errorLog)), true) {
    if (libsbmlPINVOKE.SWIGPendingException.Pending) throw libsbmlPINVOKE.SWIGPendingException.Retrieve();
  }

  
/**
   * Creates a new XMLInputStream.
   *
   * @param content the source of the stream.
   *
   * @param isFile a bool flag to indicate whether @p content is a file
   * name.  If @c true, @p content is assumed to be the file from which the
   * XML content is to be read.  If @c false, @p content is taken to be a
   * string that @em is the content to be read.
   *
   * @param library the name of the parser library to use.
   *
   * @param errorLog the XMLErrorLog object to use.
   *
   * @ifnot hasDefaultArgs @htmlinclude warn-default-args-in-docs.html @endif
   */ public
 XMLInputStream(string content, bool isFile, string library) : this(libsbmlPINVOKE.new_XMLInputStream__SWIG_1(content, isFile, library), true) {
    if (libsbmlPINVOKE.SWIGPendingException.Pending) throw libsbmlPINVOKE.SWIGPendingException.Retrieve();
  }

  
/**
   * Creates a new XMLInputStream.
   *
   * @param content the source of the stream.
   *
   * @param isFile a bool flag to indicate whether @p content is a file
   * name.  If @c true, @p content is assumed to be the file from which the
   * XML content is to be read.  If @c false, @p content is taken to be a
   * string that @em is the content to be read.
   *
   * @param library the name of the parser library to use.
   *
   * @param errorLog the XMLErrorLog object to use.
   *
   * @ifnot hasDefaultArgs @htmlinclude warn-default-args-in-docs.html @endif
   */ public
 XMLInputStream(string content, bool isFile) : this(libsbmlPINVOKE.new_XMLInputStream__SWIG_2(content, isFile), true) {
  }

  
/**
   * Creates a new XMLInputStream.
   *
   * @param content the source of the stream.
   *
   * @param isFile a bool flag to indicate whether @p content is a file
   * name.  If @c true, @p content is assumed to be the file from which the
   * XML content is to be read.  If @c false, @p content is taken to be a
   * string that @em is the content to be read.
   *
   * @param library the name of the parser library to use.
   *
   * @param errorLog the XMLErrorLog object to use.
   *
   * @ifnot hasDefaultArgs @htmlinclude warn-default-args-in-docs.html @endif
   */ public
 XMLInputStream(string content) : this(libsbmlPINVOKE.new_XMLInputStream__SWIG_3(content), true) {
  }

  
/**
   * Returns the encoding of the XML stream.
   *
   * *
 *  The @em encoding is indicated by the <code>xml</code> declaration at the
 * beginning of an XML document or data stream.  The form of this declaration
 * is
 * @verbatim
<?xml version='1.0' encoding='UTF-8'?>
@endverbatim
 * Note that the SBML specifications require the use of UTF-8 encoding, so
 * for SBML documents, the value returned by this method will always be
 * the string <code>'UTF-8'</code>.
 *
 * 
   *
   * @return the encoding of the XML stream.
   *
   * @see getVersion()
   */ public
 string getEncoding() {
    string ret = libsbmlPINVOKE.XMLInputStream_getEncoding(swigCPtr);
    return ret;
  }

  
/**
   * Returns the version of the XML stream.
   *
   * *
 *  The @em version is indicated by the <code>xml</code> declaration at the
 * beginning of an XML document or data stream.  The form of this declaration
 * is
 * @verbatim
 <?xml version='1.0' encoding='UTF-8'?>
@endverbatim
 * Note that the SBML specifications require the use of version 1.0, so
 * for SBML documents, the value returned by this method will always be
 * the string <code>'1.0'</code>. 
   *
   * @return the version of the XML stream.
   *
   * @see getEncoding()
   */ public
 string getVersion() {
    string ret = libsbmlPINVOKE.XMLInputStream_getVersion(swigCPtr);
    return ret;
  }

  
/**
   * Returns the XMLErrorLog used to log parsing problems.
   *
   * @return the XMLErrorLog used to log XML parse errors and other
   * validation errors (and messages).
   */ public
 XMLErrorLog getErrorLog() {
    IntPtr cPtr = libsbmlPINVOKE.XMLInputStream_getErrorLog(swigCPtr);
    XMLErrorLog ret = (cPtr == IntPtr.Zero) ? null : new XMLErrorLog(cPtr, false);
    return ret;
  }

  
/**
   * Returns @c true if end of file (stream) has been reached.
   *
   * @return @c true if end of file (stream) has been reached, @c false
   * otherwise.
   */ public
 bool isEOF() {
    bool ret = libsbmlPINVOKE.XMLInputStream_isEOF(swigCPtr);
    return ret;
  }

  
/**
   * Returns @c true if a fatal error occurred while reading from this
   * stream.
   *
   * @return @c true if a fatal error occurred while reading from this
   * stream.
   */ public
 bool isError() {
    bool ret = libsbmlPINVOKE.XMLInputStream_isError(swigCPtr);
    return ret;
  }

  
/**
   * Returns @c true if the stream is in a good state.
   *
   * The definition of 'good state' is that isEOF() and isError() both return
   * @c false.
   *
   * @return @c true if the stream is in a good state, @c false otherwise.
   */ public
 bool isGood() {
    bool ret = libsbmlPINVOKE.XMLInputStream_isGood(swigCPtr);
    return ret;
  }

  
/**
   * Returns the next token on this XML input stream.
   *
   * The token is consumed in the process.
   *
   * @return the next XMLToken, or an EOF token (i.e.,
   * <code>XMLToken.isEOF() == true</code>).
   *
   * @see peek()
   */ public
 XMLToken next() {
    XMLToken ret = new XMLToken(libsbmlPINVOKE.XMLInputStream_next(swigCPtr), true);
    return ret;
  }

  
/**
   * Returns the next token @em without consuming it.
   *
   * A subsequent call to either peek() or next() will return the same token.
   *
   * @return the next XMLToken or EOF (XMLToken.isEOF() == true).
   *
   * @see next()
   */ public
 XMLToken peek() {
    XMLToken ret = new XMLToken(libsbmlPINVOKE.XMLInputStream_peek(swigCPtr), false);
    return ret;
  }

  
/**
   * Consume zero or more tokens up to and including the corresponding end
   * element or EOF.
   *
   * @param element the element whose end will be sought in the input stream.
   */ public
 void skipPastEnd(XMLToken element) {
    libsbmlPINVOKE.XMLInputStream_skipPastEnd(swigCPtr, XMLToken.getCPtr(element));
    if (libsbmlPINVOKE.SWIGPendingException.Pending) throw libsbmlPINVOKE.SWIGPendingException.Retrieve();
  }

  
/**
   * Consume zero or more tokens up to but not including the next XML element
   * or EOF.
   */ public
 void skipText() {
    libsbmlPINVOKE.XMLInputStream_skipText(swigCPtr);
  }

  
/**
   * Sets the XMLErrorLog this stream will use to log errors.
   *
   * *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 *
 *
   * @li @link libsbml#LIBSBML_OPERATION_SUCCESS LIBSBML_OPERATION_SUCCESS@endlink
   * @li @link libsbml#LIBSBML_OPERATION_FAILED LIBSBML_OPERATION_FAILED@endlink
   */ public
 int setErrorLog(XMLErrorLog log) {
    int ret = libsbmlPINVOKE.XMLInputStream_setErrorLog(swigCPtr, XMLErrorLog.getCPtr(log));
    return ret;
  }

  
/**
   * Prints a string representation of the underlying token stream.
   *
   * @return a string representing the underlying XML token stream.
   *
   * @note This method is intended for debugging purposes.
   */ public
 string toString() {
    string ret = libsbmlPINVOKE.XMLInputStream_toString(swigCPtr);
    return ret;
  }

  
/**
   * Returns the SBMLNamespaces object attached to this XMLInputStream.
   *
   * @return the SBMLNamespaces object or @c null if none has been set.
   */ public
 SBMLNamespaces getSBMLNamespaces() {
	SBMLNamespaces ret
	    = (SBMLNamespaces) libsbml.DowncastSBMLNamespaces(libsbmlPINVOKE.XMLInputStream_getSBMLNamespaces(swigCPtr), false);
	return ret;
}

  
/**
   * Sets the SBML namespaces associated with this XML input stream.
   *
   * This allows this stream to reference the available SBML namespaces being
   * read.
   *
   * @param sbmlns the list of namespaces to use.
   */ public
 void setSBMLNamespaces(SBMLNamespaces sbmlns) {
    libsbmlPINVOKE.XMLInputStream_setSBMLNamespaces(swigCPtr, SBMLNamespaces.getCPtr(sbmlns));
  }

  
/**
   * Returns the number of child tokens of the given element in this stream.
   *
   * This method allows information from the input stream to be determined
   * without the need to actually read and consume the tokens in the stream.
   * It returns the number of child elements of the element represented by
   * the @p elementName, i.e., the number of child elements encountered
   * before the closing tag for the @p elementName supplied.
   *
   * If no @p elementName is supplied or it is an empty string, then as a
   * special case, this method assumes the element is a MathML
   * <code>apply</code> element followed by a function name.
   *
   * @param elementName a string representing the name of the element for
   * which the number of children are to be determined.
   *
   * @return a long integer giving the number of children of the @p
   * elementName specified.
   *
   * @note This method assumes the stream has been read up to and including
   * the element @p elementName.
   *
   * @ifnot hasDefaultArgs @htmlinclude warn-default-args-in-docs.html @endif
   */ public
 long determineNumberChildren(string elementName) { return (long)libsbmlPINVOKE.XMLInputStream_determineNumberChildren__SWIG_0(swigCPtr, elementName); }

  
/**
   * Returns the number of child tokens of the given element in this stream.
   *
   * This method allows information from the input stream to be determined
   * without the need to actually read and consume the tokens in the stream.
   * It returns the number of child elements of the element represented by
   * the @p elementName, i.e., the number of child elements encountered
   * before the closing tag for the @p elementName supplied.
   *
   * If no @p elementName is supplied or it is an empty string, then as a
   * special case, this method assumes the element is a MathML
   * <code>apply</code> element followed by a function name.
   *
   * @param elementName a string representing the name of the element for
   * which the number of children are to be determined.
   *
   * @return a long integer giving the number of children of the @p
   * elementName specified.
   *
   * @note This method assumes the stream has been read up to and including
   * the element @p elementName.
   *
   * @ifnot hasDefaultArgs @htmlinclude warn-default-args-in-docs.html @endif
   */ public
 long determineNumberChildren() { return (long)libsbmlPINVOKE.XMLInputStream_determineNumberChildren__SWIG_1(swigCPtr); }

  
/**
   * Returns the number of child tokens of the specified type within a
   * given container element.
   *
   * This method allows information from the input stream to be determined
   * without the need to actually read and consume the tokens in the stream.
   * It returns the number of child elements of the @p childName element
   * within the element specified by @p container.  In other words, it counts
   * the number of @p childName elements encountered before the closing tag
   * for the @p container supplied.
   *
   * @param childName a string representing the name of the child
   * element whose number is to be determined.
   *
   * @param container a string representing the name of the element
   * for which the number of children are to be determined.
   *
   * @return a long integer giving the number of children of type @p
   * childName within the @p container element.
   *
   * @note This method assumes the stream has been read up to and including
   * the element @p container.
   */ public
 long determineNumSpecificChildren(string childName, string container) { return (long)libsbmlPINVOKE.XMLInputStream_determineNumSpecificChildren(swigCPtr, childName, container); }

}

}
