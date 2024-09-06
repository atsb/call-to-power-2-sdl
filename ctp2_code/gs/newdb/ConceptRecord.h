
/*
 * DO NOT EDIT THIS FILE!
 * It is generated automatically by ctpdb
 */

#if defined(HAVE_PRAGMA_ONCE)
#pragma once
#endif

#ifndef CONCEPT_RECORD_H__
#define CONCEPT_RECORD_H__

class ConceptRecord;

#include "CTPDatabase.h"
#include "CTPRecord.h"
class CivArchive;
class IconRecord;

#define k_Num_ConceptRecord_Tokens 2

//
// m_flags0: Concept
#define k_Concept_GLHidden_Bit                   0x00000001

class ConceptRecord : public CTPRecord
{
public:
    typedef sint32 (ConceptRecord::*IntAccessor)() const;
    typedef bool   (ConceptRecord::*BoolAccessor)() const;
    typedef double (ConceptRecord::*FloatAccessor)() const ;
    typedef bool   (ConceptRecord::*BitIntAccessor)(sint32 &val) const;
    typedef bool   (ConceptRecord::*BitFloatAccessor)(double &val) const;
    typedef sint32 (ConceptRecord::*IntArrayAccessor)(sint32 index) const;
    typedef double (ConceptRecord::*FloatArrayAccessor)(sint32 index) const;

private:
    uint32 m_flags0;
    sint32            m_DefaultIcon; // Index into Icon database
    bool m_hasGovernmentsModified; // GovMod specific flag

public:
    ConceptRecord() { Init(); };
    ConceptRecord(CivArchive &archive) { Serialize(archive); };
    ConceptRecord(ConceptRecord const & rval) { Init(); *this = rval; }
    ~ConceptRecord();
    ConceptRecord const & operator = (ConceptRecord const & rval);

    void Init();
    void Serialize(CivArchive &archive);

    void CheckRequiredFields(DBLexer *lex);
    sint32 Parse(DBLexer *lex, sint32 numRecords);

    void ResolveDBReferences();
    void Merge(const ConceptRecord & rval);

    sint32           GetDefaultIconIndex() const { return m_DefaultIcon; }
    IconRecord const * GetDefaultIcon() const;
    bool GetGLHidden() const { return (m_flags0 & k_Concept_GLHidden_Bit) != 0; }
    bool GetHasGovernmentsModified() const { return m_hasGovernmentsModified; }
    sint32 GenericGetNumGovernmentsModified() const { return 0; }
    sint32 GenericGetGovernmentsModifiedIndex(sint32 index) const { return -1; }

}; /* ConceptRecord */

struct ConceptRecordAccessorInfo
{
    ConceptRecord::IntAccessor        m_intAccessor;
    ConceptRecord::BoolAccessor       m_boolAccessor;
    ConceptRecord::FloatAccessor      m_floatAccessor;
    ConceptRecord::BitIntAccessor     m_bitIntAccessor;
    ConceptRecord::BitFloatAccessor   m_bitFloatAccessor;
    ConceptRecord::IntArrayAccessor   m_intArrayAccessor;
    ConceptRecord::FloatArrayAccessor m_floatArrayAccessor;
};

extern ConceptRecordAccessorInfo      g_ConceptRecord_Accessors[];
extern CTPDatabase<ConceptRecord> *   g_theConceptDB;

extern const char * g_Concept_Tokens[];

#endif
