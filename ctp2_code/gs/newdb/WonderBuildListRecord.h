
/*
 * DO NOT EDIT THIS FILE!
 * It is generated automatically by ctpdb
 */

#if defined(HAVE_PRAGMA_ONCE)
#pragma once
#endif

#ifndef WONDERBUILDLIST_RECORD_H__
#define WONDERBUILDLIST_RECORD_H__

class WonderBuildListRecord;

#include "CTPDatabase.h"
#include "CTPRecord.h"
class CivArchive;
class WonderRecord;

#define k_Num_WonderBuildListRecord_Tokens 1


class WonderBuildListRecord : public CTPRecord
{
public:
    typedef sint32 (WonderBuildListRecord::*IntAccessor)() const;
    typedef bool   (WonderBuildListRecord::*BoolAccessor)() const;
    typedef double (WonderBuildListRecord::*FloatAccessor)() const ;
    typedef bool   (WonderBuildListRecord::*BitIntAccessor)(sint32 &val) const;
    typedef bool   (WonderBuildListRecord::*BitFloatAccessor)(double &val) const;
    typedef sint32 (WonderBuildListRecord::*IntArrayAccessor)(sint32 index) const;
    typedef double (WonderBuildListRecord::*FloatArrayAccessor)(sint32 index) const;

private:
    sint32          * m_Wonder; // Index into Wonder database
    sint32            m_numWonder;
    bool m_hasGovernmentsModified; // GovMod specific flag

public:
    WonderBuildListRecord() { Init(); };
    WonderBuildListRecord(CivArchive &archive) { Serialize(archive); };
    WonderBuildListRecord(WonderBuildListRecord const & rval) { Init(); *this = rval; }
    ~WonderBuildListRecord();
    WonderBuildListRecord const & operator = (WonderBuildListRecord const & rval);

    void Init();
    void Serialize(CivArchive &archive);

    void CheckRequiredFields(DBLexer *lex);
    sint32 Parse(DBLexer *lex, sint32 numRecords);

    void ResolveDBReferences();
    void Merge(const WonderBuildListRecord & rval);

    sint32 GetWonderIndex(sint32 index) const;
    const WonderRecord * GetWonder(sint32 index) const;
    sint32 GetNumWonder() const { return m_numWonder;}
    bool GetHasGovernmentsModified() const { return m_hasGovernmentsModified; }
    sint32 GenericGetNumGovernmentsModified() const { return 0; }
    sint32 GenericGetGovernmentsModifiedIndex(sint32 index) const { return -1; }

}; /* WonderBuildListRecord */

struct WonderBuildListRecordAccessorInfo
{
    WonderBuildListRecord::IntAccessor        m_intAccessor;
    WonderBuildListRecord::BoolAccessor       m_boolAccessor;
    WonderBuildListRecord::FloatAccessor      m_floatAccessor;
    WonderBuildListRecord::BitIntAccessor     m_bitIntAccessor;
    WonderBuildListRecord::BitFloatAccessor   m_bitFloatAccessor;
    WonderBuildListRecord::IntArrayAccessor   m_intArrayAccessor;
    WonderBuildListRecord::FloatArrayAccessor m_floatArrayAccessor;
};

extern WonderBuildListRecordAccessorInfo      g_WonderBuildListRecord_Accessors[];
extern CTPDatabase<WonderBuildListRecord> *   g_theWonderBuildListDB;

extern const char * g_WonderBuildList_Tokens[];

#endif
