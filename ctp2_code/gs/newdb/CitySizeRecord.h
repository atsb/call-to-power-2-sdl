
/*
 * DO NOT EDIT THIS FILE!
 * It is generated automatically by ctpdb
 */

#if defined(HAVE_PRAGMA_ONCE)
#pragma once
#endif

#ifndef CITYSIZE_RECORD_H__
#define CITYSIZE_RECORD_H__

class CitySizeRecord;

#include "CTPDatabase.h"
#include "CTPRecord.h"
class CivArchive;

#define k_Num_CitySizeRecord_Tokens 10


class CitySizeRecord : public CTPRecord
{
public:
    typedef sint32 (CitySizeRecord::*IntAccessor)() const;
    typedef bool   (CitySizeRecord::*BoolAccessor)() const;
    typedef double (CitySizeRecord::*FloatAccessor)() const ;
    typedef bool   (CitySizeRecord::*BitIntAccessor)(sint32 &val) const;
    typedef bool   (CitySizeRecord::*BitFloatAccessor)(double &val) const;
    typedef sint32 (CitySizeRecord::*IntArrayAccessor)(sint32 index) const;
    typedef double (CitySizeRecord::*FloatArrayAccessor)(sint32 index) const;

private:
    sint32            m_Population;
    sint32            m_SquaredRadius;
    sint32            m_IntRadius;
    double            m_VisionRadius;
    sint32            m_MaxWorkers;
    sint32            m_GrowthRate;
    sint32            m_MinGrowthRate;
    sint32            m_MaxSurplusFood;
    sint32            m_BaseOvercrowding;
    sint32            m_BaseMaxPop;
    bool m_hasGovernmentsModified; // GovMod specific flag

public:
    CitySizeRecord() { Init(); };
    CitySizeRecord(CivArchive &archive) { Serialize(archive); };
    CitySizeRecord(CitySizeRecord const & rval) { Init(); *this = rval; }
    ~CitySizeRecord();
    CitySizeRecord const & operator = (CitySizeRecord const & rval);

    void Init();
    void Serialize(CivArchive &archive);

    void CheckRequiredFields(DBLexer *lex);
    sint32 Parse(DBLexer *lex, sint32 numRecords);

    void ResolveDBReferences();
    void Merge(const CitySizeRecord & rval);

    sint32 GetPopulation() const { return m_Population; }
    sint32 GetSquaredRadius() const { return m_SquaredRadius; }
    sint32 GetIntRadius() const { return m_IntRadius; }
    double GetVisionRadius() const { return m_VisionRadius; }
    sint32 GetMaxWorkers() const { return m_MaxWorkers; }
    sint32 GetGrowthRate() const { return m_GrowthRate; }
    sint32 GetMinGrowthRate() const { return m_MinGrowthRate; }
    sint32 GetMaxSurplusFood() const { return m_MaxSurplusFood; }
    sint32 GetBaseOvercrowding() const { return m_BaseOvercrowding; }
    sint32 GetBaseMaxPop() const { return m_BaseMaxPop; }
    bool GetHasGovernmentsModified() const { return m_hasGovernmentsModified; }
    sint32 GenericGetNumGovernmentsModified() const { return 0; }
    sint32 GenericGetGovernmentsModifiedIndex(sint32 index) const { return -1; }

}; /* CitySizeRecord */

struct CitySizeRecordAccessorInfo
{
    CitySizeRecord::IntAccessor        m_intAccessor;
    CitySizeRecord::BoolAccessor       m_boolAccessor;
    CitySizeRecord::FloatAccessor      m_floatAccessor;
    CitySizeRecord::BitIntAccessor     m_bitIntAccessor;
    CitySizeRecord::BitFloatAccessor   m_bitFloatAccessor;
    CitySizeRecord::IntArrayAccessor   m_intArrayAccessor;
    CitySizeRecord::FloatArrayAccessor m_floatArrayAccessor;
};

extern CitySizeRecordAccessorInfo      g_CitySizeRecord_Accessors[];
extern CTPDatabase<CitySizeRecord> *   g_theCitySizeDB;

extern const char * g_CitySize_Tokens[];

#endif
