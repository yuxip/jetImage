// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME PjetDict

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "Ptrack.h"
#include "Pjet.h"
#include "Pevent.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_Ptrack(void *p = 0);
   static void *newArray_Ptrack(Long_t size, void *p);
   static void delete_Ptrack(void *p);
   static void deleteArray_Ptrack(void *p);
   static void destruct_Ptrack(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Ptrack*)
   {
      ::Ptrack *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Ptrack >(0);
      static ::ROOT::TGenericClassInfo 
         instance("Ptrack", ::Ptrack::Class_Version(), "Ptrack.h", 14,
                  typeid(::Ptrack), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Ptrack::Dictionary, isa_proxy, 4,
                  sizeof(::Ptrack) );
      instance.SetNew(&new_Ptrack);
      instance.SetNewArray(&newArray_Ptrack);
      instance.SetDelete(&delete_Ptrack);
      instance.SetDeleteArray(&deleteArray_Ptrack);
      instance.SetDestructor(&destruct_Ptrack);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Ptrack*)
   {
      return GenerateInitInstanceLocal((::Ptrack*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::Ptrack*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_Pjet(void *p = 0);
   static void *newArray_Pjet(Long_t size, void *p);
   static void delete_Pjet(void *p);
   static void deleteArray_Pjet(void *p);
   static void destruct_Pjet(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Pjet*)
   {
      ::Pjet *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Pjet >(0);
      static ::ROOT::TGenericClassInfo 
         instance("Pjet", ::Pjet::Class_Version(), "Pjet.h", 15,
                  typeid(::Pjet), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Pjet::Dictionary, isa_proxy, 4,
                  sizeof(::Pjet) );
      instance.SetNew(&new_Pjet);
      instance.SetNewArray(&newArray_Pjet);
      instance.SetDelete(&delete_Pjet);
      instance.SetDeleteArray(&deleteArray_Pjet);
      instance.SetDestructor(&destruct_Pjet);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Pjet*)
   {
      return GenerateInitInstanceLocal((::Pjet*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::Pjet*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_Pevent(void *p = 0);
   static void *newArray_Pevent(Long_t size, void *p);
   static void delete_Pevent(void *p);
   static void deleteArray_Pevent(void *p);
   static void destruct_Pevent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Pevent*)
   {
      ::Pevent *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Pevent >(0);
      static ::ROOT::TGenericClassInfo 
         instance("Pevent", ::Pevent::Class_Version(), "Pevent.h", 15,
                  typeid(::Pevent), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Pevent::Dictionary, isa_proxy, 4,
                  sizeof(::Pevent) );
      instance.SetNew(&new_Pevent);
      instance.SetNewArray(&newArray_Pevent);
      instance.SetDelete(&delete_Pevent);
      instance.SetDeleteArray(&deleteArray_Pevent);
      instance.SetDestructor(&destruct_Pevent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Pevent*)
   {
      return GenerateInitInstanceLocal((::Pevent*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::Pevent*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr Ptrack::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *Ptrack::Class_Name()
{
   return "Ptrack";
}

//______________________________________________________________________________
const char *Ptrack::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Ptrack*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int Ptrack::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Ptrack*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Ptrack::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Ptrack*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Ptrack::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Ptrack*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr Pjet::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *Pjet::Class_Name()
{
   return "Pjet";
}

//______________________________________________________________________________
const char *Pjet::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Pjet*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int Pjet::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Pjet*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Pjet::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Pjet*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Pjet::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Pjet*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr Pevent::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *Pevent::Class_Name()
{
   return "Pevent";
}

//______________________________________________________________________________
const char *Pevent::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Pevent*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int Pevent::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Pevent*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Pevent::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Pevent*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Pevent::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Pevent*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void Ptrack::Streamer(TBuffer &R__b)
{
   // Stream an object of class Ptrack.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(Ptrack::Class(),this);
   } else {
      R__b.WriteClassBuffer(Ptrack::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Ptrack(void *p) {
      return  p ? new(p) ::Ptrack : new ::Ptrack;
   }
   static void *newArray_Ptrack(Long_t nElements, void *p) {
      return p ? new(p) ::Ptrack[nElements] : new ::Ptrack[nElements];
   }
   // Wrapper around operator delete
   static void delete_Ptrack(void *p) {
      delete ((::Ptrack*)p);
   }
   static void deleteArray_Ptrack(void *p) {
      delete [] ((::Ptrack*)p);
   }
   static void destruct_Ptrack(void *p) {
      typedef ::Ptrack current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Ptrack

//______________________________________________________________________________
void Pjet::Streamer(TBuffer &R__b)
{
   // Stream an object of class Pjet.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(Pjet::Class(),this);
   } else {
      R__b.WriteClassBuffer(Pjet::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Pjet(void *p) {
      return  p ? new(p) ::Pjet : new ::Pjet;
   }
   static void *newArray_Pjet(Long_t nElements, void *p) {
      return p ? new(p) ::Pjet[nElements] : new ::Pjet[nElements];
   }
   // Wrapper around operator delete
   static void delete_Pjet(void *p) {
      delete ((::Pjet*)p);
   }
   static void deleteArray_Pjet(void *p) {
      delete [] ((::Pjet*)p);
   }
   static void destruct_Pjet(void *p) {
      typedef ::Pjet current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Pjet

//______________________________________________________________________________
void Pevent::Streamer(TBuffer &R__b)
{
   // Stream an object of class Pevent.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(Pevent::Class(),this);
   } else {
      R__b.WriteClassBuffer(Pevent::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Pevent(void *p) {
      return  p ? new(p) ::Pevent : new ::Pevent;
   }
   static void *newArray_Pevent(Long_t nElements, void *p) {
      return p ? new(p) ::Pevent[nElements] : new ::Pevent[nElements];
   }
   // Wrapper around operator delete
   static void delete_Pevent(void *p) {
      delete ((::Pevent*)p);
   }
   static void deleteArray_Pevent(void *p) {
      delete [] ((::Pevent*)p);
   }
   static void destruct_Pevent(void *p) {
      typedef ::Pevent current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Pevent

namespace ROOT {
   static TClass *vectorlEPtrackmUgR_Dictionary();
   static void vectorlEPtrackmUgR_TClassManip(TClass*);
   static void *new_vectorlEPtrackmUgR(void *p = 0);
   static void *newArray_vectorlEPtrackmUgR(Long_t size, void *p);
   static void delete_vectorlEPtrackmUgR(void *p);
   static void deleteArray_vectorlEPtrackmUgR(void *p);
   static void destruct_vectorlEPtrackmUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<Ptrack*>*)
   {
      vector<Ptrack*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<Ptrack*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<Ptrack*>", -2, "vector", 214,
                  typeid(vector<Ptrack*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEPtrackmUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<Ptrack*>) );
      instance.SetNew(&new_vectorlEPtrackmUgR);
      instance.SetNewArray(&newArray_vectorlEPtrackmUgR);
      instance.SetDelete(&delete_vectorlEPtrackmUgR);
      instance.SetDeleteArray(&deleteArray_vectorlEPtrackmUgR);
      instance.SetDestructor(&destruct_vectorlEPtrackmUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<Ptrack*> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<Ptrack*>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEPtrackmUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<Ptrack*>*)0x0)->GetClass();
      vectorlEPtrackmUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEPtrackmUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEPtrackmUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<Ptrack*> : new vector<Ptrack*>;
   }
   static void *newArray_vectorlEPtrackmUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<Ptrack*>[nElements] : new vector<Ptrack*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEPtrackmUgR(void *p) {
      delete ((vector<Ptrack*>*)p);
   }
   static void deleteArray_vectorlEPtrackmUgR(void *p) {
      delete [] ((vector<Ptrack*>*)p);
   }
   static void destruct_vectorlEPtrackmUgR(void *p) {
      typedef vector<Ptrack*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<Ptrack*>

namespace ROOT {
   static TClass *vectorlEPjetmUgR_Dictionary();
   static void vectorlEPjetmUgR_TClassManip(TClass*);
   static void *new_vectorlEPjetmUgR(void *p = 0);
   static void *newArray_vectorlEPjetmUgR(Long_t size, void *p);
   static void delete_vectorlEPjetmUgR(void *p);
   static void deleteArray_vectorlEPjetmUgR(void *p);
   static void destruct_vectorlEPjetmUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<Pjet*>*)
   {
      vector<Pjet*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<Pjet*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<Pjet*>", -2, "vector", 214,
                  typeid(vector<Pjet*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEPjetmUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<Pjet*>) );
      instance.SetNew(&new_vectorlEPjetmUgR);
      instance.SetNewArray(&newArray_vectorlEPjetmUgR);
      instance.SetDelete(&delete_vectorlEPjetmUgR);
      instance.SetDeleteArray(&deleteArray_vectorlEPjetmUgR);
      instance.SetDestructor(&destruct_vectorlEPjetmUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<Pjet*> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<Pjet*>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEPjetmUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<Pjet*>*)0x0)->GetClass();
      vectorlEPjetmUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEPjetmUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEPjetmUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<Pjet*> : new vector<Pjet*>;
   }
   static void *newArray_vectorlEPjetmUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<Pjet*>[nElements] : new vector<Pjet*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEPjetmUgR(void *p) {
      delete ((vector<Pjet*>*)p);
   }
   static void deleteArray_vectorlEPjetmUgR(void *p) {
      delete [] ((vector<Pjet*>*)p);
   }
   static void destruct_vectorlEPjetmUgR(void *p) {
      typedef vector<Pjet*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<Pjet*>

namespace {
  void TriggerDictionaryInitialization_PjetDict_Impl() {
    static const char* headers[] = {
"Ptrack.h",
"Pjet.h",
"Pevent.h",
0
    };
    static const char* includePaths[] = {
"/home/osboxes/bjet/root-install/include",
"/home/osboxes/bjet/jet-fast/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "PjetDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$Ptrack.h")))  Ptrack;
class __attribute__((annotate("$clingAutoload$Pjet.h")))  Pjet;
class __attribute__((annotate("$clingAutoload$Pevent.h")))  Pevent;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "PjetDict dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "Ptrack.h"
#include "Pjet.h"
#include "Pevent.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"Pevent", payloadCode, "@",
"Pjet", payloadCode, "@",
"Ptrack", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("PjetDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_PjetDict_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_PjetDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_PjetDict() {
  TriggerDictionaryInitialization_PjetDict_Impl();
}
