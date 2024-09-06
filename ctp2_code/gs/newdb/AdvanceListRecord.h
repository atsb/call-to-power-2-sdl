
/*
 * DO NOT EDIT THIS FILE!
 * It is generated automatically by ctpdb
 */

#if defined(HAVE_PRAGMA_ONCE)
#pragma once
#endif

#ifndef ADVANCELIST_RECORD_H__
#define ADVANCELIST_RECORD_H__

class AdvanceListRecord;

#include "CTPDatabase.h"
#include "CTPRecord.h"
class CivArchive;
class AdvanceRecord;

#define k_Num_AdvanceListRecord_Tokens 1


class AdvanceListRecord : public CTPRecord
{
public:
    typedef sint32 (AdvanceListRecord::*IntAccessor)() const;
    typedef bool   (AdvanceListRecord::*BoolAccessor)() const;
    typedef double (AdvanceListRecord::*FloatAccessor)() const ;
    typedef bool   (AdvanceListRecord::*BitIntAccessor)(sint32 &val) const;
    typedef bool   (AdvanceListRecord::*BitFloatAccessor)(double &val) const;
    typedef sint32 (AdvanceListRecord::*IntArrayAccessor)(sint32 index) const;
    typedef double (AdvanceListRecord::*FloatArrayAccessor)(sint32 index) const;

private:
    sint32          * m_Advance; // Index into Advance database
    sint32            m_numAdvance;
    bool m_hasGovernmentsModified; // GovMod specific flag

public:
    AdvanceListRecord() { Init(); };
    AdvanceListRecord(CivArchive &archive) { Serialize(archive); };
    AdvanceListRecord(AdvanceListRecord const & rval) { Init(); *this = rval; }
    ~AdvanceListRecord();
    AdvanceListRecord const & operator = (AdvanceListRecord const & rval);

    void Init();
    void Serialize(CivArchive &archive);

    void CheckRequiredFields(DBLexer *lex);
    sint32 Parse(DBLexer *lex, sint32 numRecords);

    void ResolveDBReferences();
    void Merge(const AdvanceListRecord & rval);

    sint32 GetAdvanceIndex(sint32 index) const;
    const AdvanceRecord * GetAdvance(sint32 index) const;
    sint32 GetNumAdvance() const { return m_numAdvance;}
    bool GetHasGovernmentsModified() const { return m_hasGovernmentsModified; }
    sint32 GenericGetNumGovernmentsModified() const { return 0; }
    sint32 GenericGetGovernmentsModifiedIndex(sint32 index) const { return -1; }

}; /* AdvanceListRecord */

struct AdvanceListRecordAccessorInfo
{
    AdvanceListRecord::IntAccessor        m_intAccessor;
    AdvanceListRecord::BoolAccessor       m_boolAccessor;
    AdvanceListRecord::FloatAccessor      m_floatAccessor;
    AdvanceListRecord::BitIntAccessor     m_bitIntAccessor;
    AdvanceListRecord::BitFloatAccessor   m_bitFloatAccessor;
    AdvanceListRecord::IntArrayAccessor   m_intArrayAccessor;
    AdvanceListRecord::FloatArrayAccessor m_floatArrayAccessor;
};

extern AdvanceListRecordAccessorInfo      g_AdvanceListRecord_Accessors[];
extern CTPDatabase<AdvanceListRecord> *   g_theAdvanceListDB;

extern const char * g_AdvanceList_Tokens[];

#endif
