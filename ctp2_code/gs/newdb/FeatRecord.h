
/*
 * DO NOT EDIT THIS FILE!
 * It is generated automatically by ctpdb
 */

#if defined(HAVE_PRAGMA_ONCE)
#pragma once
#endif

#ifndef FEAT_RECORD_H__
#define FEAT_RECORD_H__

class FeatRecord;

#include "CTPDatabase.h"
#include "CTPRecord.h"
class CivArchive;
class AdvanceRecord;
class GovernmentRecord;
class WonderRecord;
class BuildingRecord;
class TerrainImprovementRecord;

#define k_Num_FeatRecord_Tokens 49

//
// m_flags0: Feat
#define k_Feat_SlicMessage_Bit                   0x00000001
#define k_Feat_EffectBoatMovement_Bit            0x00000002
#define k_Feat_EffectCityDefenseBonus_Bit        0x00000004
#define k_Feat_EffectReduceCityWalls_Bit         0x00000008
#define k_Feat_EffectIncreaseCityVision_Bit      0x00000010
#define k_Feat_EffectIncreaseProduction_Bit      0x00000020
#define k_Feat_EffectIncreaseCommerce_Bit        0x00000040
#define k_Feat_EffectIncreaseHappiness_Bit       0x00000080
#define k_Feat_EffectEliminateDistancePenalty_Bit 0x00000100
#define k_Feat_EffectIncreaseBoatVision_Bit      0x00000200
#define k_Feat_EffectIncreaseScience_Bit         0x00000400
#define k_Feat_EffectGiveMaps_Bit                0x00000800
#define k_Feat_EffectIncreaseHitPoints_Bit       0x00001000
#define k_Feat_EffectScriptedTurn_Bit            0x00002000
#define k_Feat_EffectScriptedCity_Bit            0x00004000
#define k_Feat_ExcludeFunction_Bit               0x00008000
#define k_Feat_CancelFunction_Bit                0x00010000
#define k_Feat_Building_Bit                      0x00020000
#define k_Feat_MinimumSizeOfCiv_Bit              0x00040000
#define k_Feat_TileImp_Bit                       0x00080000
//
// m_flags0: BuildingFeat
#define k_BuildingFeat_Num_Bit                   0x00000001
#define k_BuildingFeat_PercentCities_Bit         0x00000002
//
// m_flags0: InfrastructureFeat
#define k_InfrastructureFeat_Num_Bit             0x00000001

class FeatRecord : public CTPRecord
{
public:
    typedef sint32 (FeatRecord::*IntAccessor)() const;
    typedef bool   (FeatRecord::*BoolAccessor)() const;
    typedef double (FeatRecord::*FloatAccessor)() const ;
    typedef bool   (FeatRecord::*BitIntAccessor)(sint32 &val) const;
    typedef bool   (FeatRecord::*BitFloatAccessor)(double &val) const;
    typedef sint32 (FeatRecord::*IntArrayAccessor)(sint32 index) const;
    typedef double (FeatRecord::*FloatArrayAccessor)(sint32 index) const;

    class BuildingFeat {
    private:
        uint32            m_flags0;
        sint32            m_Building; // Index into Building database
        sint32            m_NumValue;
        sint32            m_PercentCitiesValue;

    public:
        BuildingFeat();
        BuildingFeat(CivArchive & archive){ Serialize(archive); };
        ~BuildingFeat();
        BuildingFeat const & operator = (BuildingFeat const & rval);
        bool operator == (BuildingFeat const & rval) {
          if (m_Building != rval.m_Building)
             return false;
          return true;
        }

        void Serialize(CivArchive &archive);
        sint32 Parse(DBLexer *lex);
        static sint32 ParseInArray(DBLexer *lex, BuildingFeat **array, sint32 *numElements);
        static sint32 ParseInArray(DBLexer *lex, BuildingFeat *array, sint32 *numElements, sint32 maxSize);
        void ResolveDBReferences();

        sint32           GetBuildingIndex() const { return m_Building; }
        BuildingRecord const * GetBuilding() const;
        bool HasNum() const { return (m_flags0 & k_BuildingFeat_Num_Bit) != 0; }
        bool GetNum(sint32 & value) const
        {
            if (m_flags0 & k_BuildingFeat_Num_Bit)
            {
                value = m_NumValue;
            }
            return (m_flags0 & k_BuildingFeat_Num_Bit) != 0;
        }
        bool HasPercentCities() const { return (m_flags0 & k_BuildingFeat_PercentCities_Bit) != 0; }
        bool GetPercentCities(sint32 & value) const
        {
            if (m_flags0 & k_BuildingFeat_PercentCities_Bit)
            {
                value = m_PercentCitiesValue;
            }
            return (m_flags0 & k_BuildingFeat_PercentCities_Bit) != 0;
        }

    }; /* class BuildingFeat */

    class InfrastructureFeat {
    private:
        uint32            m_flags0;
        sint32            m_TileImp; // Index into TerrainImprovement database
        sint32            m_NumValue;

    public:
        InfrastructureFeat();
        InfrastructureFeat(CivArchive & archive){ Serialize(archive); };
        ~InfrastructureFeat();
        InfrastructureFeat const & operator = (InfrastructureFeat const & rval);
        bool operator == (InfrastructureFeat const & rval) {
          if (m_TileImp != rval.m_TileImp)
             return false;
          return true;
        }

        void Serialize(CivArchive &archive);
        sint32 Parse(DBLexer *lex);
        static sint32 ParseInArray(DBLexer *lex, InfrastructureFeat **array, sint32 *numElements);
        static sint32 ParseInArray(DBLexer *lex, InfrastructureFeat *array, sint32 *numElements, sint32 maxSize);
        void ResolveDBReferences();

        sint32           GetTileImpIndex() const { return m_TileImp; }
        TerrainImprovementRecord const * GetTileImp() const;
        bool HasNum() const { return (m_flags0 & k_InfrastructureFeat_Num_Bit) != 0; }
        bool GetNum(sint32 & value) const
        {
            if (m_flags0 & k_InfrastructureFeat_Num_Bit)
            {
                value = m_NumValue;
            }
            return (m_flags0 & k_InfrastructureFeat_Num_Bit) != 0;
        }

    }; /* class InfrastructureFeat */

private:
    uint32 m_flags0;
    sint32            m_Duration;
    sint32            m_Description;
    char *            m_SlicMessageValue;
    sint32            m_EffectBoatMovementValue;
    sint32            m_EffectCityDefenseBonusValue;
    sint32            m_EffectReduceCityWallsValue;
    sint32            m_EffectIncreaseCityVisionValue;
    sint32            m_EffectIncreaseProductionValue;
    sint32            m_EffectIncreaseCommerceValue;
    sint32            m_EffectIncreaseHappinessValue;
    sint32            m_EffectEliminateDistancePenaltyValue;
    sint32            m_EffectIncreaseBoatVisionValue;
    sint32            m_EffectIncreaseScienceValue;
    sint32            m_EffectIncreaseHitPointsValue;
    char *            m_EffectScriptedTurnValue;
    char *            m_EffectScriptedCityValue;
    sint32          * m_ExcludeAdvance; // Index into Advance database
    sint32            m_numExcludeAdvance;
    sint32          * m_ExcludeWonder; // Index into Wonder database
    sint32            m_numExcludeWonder;
    sint32          * m_ExcludeFeat; // Index into Feat database
    sint32            m_numExcludeFeat;
    sint32          * m_GovernmentsModified; // Index into Government database
    sint32            m_numGovernmentsModified;
    char *            m_ExcludeFunctionValue;
    sint32          * m_CancelAdvance; // Index into Advance database
    sint32            m_numCancelAdvance;
    sint32          * m_CancelWonder; // Index into Wonder database
    sint32            m_numCancelWonder;
    sint32          * m_CancelFeat; // Index into Feat database
    sint32            m_numCancelFeat;
    char *            m_CancelFunctionValue;
    BuildingFeat      m_BuildingValue;
    sint32            m_MinimumSizeOfCivValue;
    InfrastructureFeat   m_TileImpValue;
    sint32          * m_GrantAdvance; // Index into Advance database
    sint32            m_numGrantAdvance;
    bool m_hasGovernmentsModified; // GovMod specific flag

public:
    FeatRecord() { Init(); };
    FeatRecord(CivArchive &archive) { Serialize(archive); };
    FeatRecord(FeatRecord const & rval) { Init(); *this = rval; }
    ~FeatRecord();
    FeatRecord const & operator = (FeatRecord const & rval);

    void Init();
    void Serialize(CivArchive &archive);

    void CheckRequiredFields(DBLexer *lex);
    sint32 Parse(DBLexer *lex, sint32 numRecords);

    void ResolveDBReferences();
    void Merge(const FeatRecord & rval);

    sint32 GetDuration() const { return m_Duration; }
    sint32 GetDescription() const { return m_Description; }
    bool HasSlicMessage() const { return (m_flags0 & k_Feat_SlicMessage_Bit) != 0; }
    bool GetSlicMessage(char const * & value) const
    {
        if (m_flags0 & k_Feat_SlicMessage_Bit)
        {
            value = m_SlicMessageValue;
        }
        return (m_flags0 & k_Feat_SlicMessage_Bit) != 0;
    }
    bool HasEffectBoatMovement() const { return (m_flags0 & k_Feat_EffectBoatMovement_Bit) != 0; }
    bool GetEffectBoatMovement(sint32 & value) const
    {
        if (m_flags0 & k_Feat_EffectBoatMovement_Bit)
        {
            value = m_EffectBoatMovementValue;
        }
        return (m_flags0 & k_Feat_EffectBoatMovement_Bit) != 0;
    }
    bool HasEffectCityDefenseBonus() const { return (m_flags0 & k_Feat_EffectCityDefenseBonus_Bit) != 0; }
    bool GetEffectCityDefenseBonus(sint32 & value) const
    {
        if (m_flags0 & k_Feat_EffectCityDefenseBonus_Bit)
        {
            value = m_EffectCityDefenseBonusValue;
        }
        return (m_flags0 & k_Feat_EffectCityDefenseBonus_Bit) != 0;
    }
    bool HasEffectReduceCityWalls() const { return (m_flags0 & k_Feat_EffectReduceCityWalls_Bit) != 0; }
    bool GetEffectReduceCityWalls(sint32 & value) const
    {
        if (m_flags0 & k_Feat_EffectReduceCityWalls_Bit)
        {
            value = m_EffectReduceCityWallsValue;
        }
        return (m_flags0 & k_Feat_EffectReduceCityWalls_Bit) != 0;
    }
    bool HasEffectIncreaseCityVision() const { return (m_flags0 & k_Feat_EffectIncreaseCityVision_Bit) != 0; }
    bool GetEffectIncreaseCityVision(sint32 & value) const
    {
        if (m_flags0 & k_Feat_EffectIncreaseCityVision_Bit)
        {
            value = m_EffectIncreaseCityVisionValue;
        }
        return (m_flags0 & k_Feat_EffectIncreaseCityVision_Bit) != 0;
    }
    bool HasEffectIncreaseProduction() const { return (m_flags0 & k_Feat_EffectIncreaseProduction_Bit) != 0; }
    bool GetEffectIncreaseProduction(sint32 & value) const
    {
        if (m_flags0 & k_Feat_EffectIncreaseProduction_Bit)
        {
            value = m_EffectIncreaseProductionValue;
        }
        return (m_flags0 & k_Feat_EffectIncreaseProduction_Bit) != 0;
    }
    bool HasEffectIncreaseCommerce() const { return (m_flags0 & k_Feat_EffectIncreaseCommerce_Bit) != 0; }
    bool GetEffectIncreaseCommerce(sint32 & value) const
    {
        if (m_flags0 & k_Feat_EffectIncreaseCommerce_Bit)
        {
            value = m_EffectIncreaseCommerceValue;
        }
        return (m_flags0 & k_Feat_EffectIncreaseCommerce_Bit) != 0;
    }
    bool HasEffectIncreaseHappiness() const { return (m_flags0 & k_Feat_EffectIncreaseHappiness_Bit) != 0; }
    bool GetEffectIncreaseHappiness(sint32 & value) const
    {
        if (m_flags0 & k_Feat_EffectIncreaseHappiness_Bit)
        {
            value = m_EffectIncreaseHappinessValue;
        }
        return (m_flags0 & k_Feat_EffectIncreaseHappiness_Bit) != 0;
    }
    bool HasEffectEliminateDistancePenalty() const { return (m_flags0 & k_Feat_EffectEliminateDistancePenalty_Bit) != 0; }
    bool GetEffectEliminateDistancePenalty(sint32 & value) const
    {
        if (m_flags0 & k_Feat_EffectEliminateDistancePenalty_Bit)
        {
            value = m_EffectEliminateDistancePenaltyValue;
        }
        return (m_flags0 & k_Feat_EffectEliminateDistancePenalty_Bit) != 0;
    }
    bool HasEffectIncreaseBoatVision() const { return (m_flags0 & k_Feat_EffectIncreaseBoatVision_Bit) != 0; }
    bool GetEffectIncreaseBoatVision(sint32 & value) const
    {
        if (m_flags0 & k_Feat_EffectIncreaseBoatVision_Bit)
        {
            value = m_EffectIncreaseBoatVisionValue;
        }
        return (m_flags0 & k_Feat_EffectIncreaseBoatVision_Bit) != 0;
    }
    bool HasEffectIncreaseScience() const { return (m_flags0 & k_Feat_EffectIncreaseScience_Bit) != 0; }
    bool GetEffectIncreaseScience(sint32 & value) const
    {
        if (m_flags0 & k_Feat_EffectIncreaseScience_Bit)
        {
            value = m_EffectIncreaseScienceValue;
        }
        return (m_flags0 & k_Feat_EffectIncreaseScience_Bit) != 0;
    }
    bool GetEffectGiveMaps() const { return (m_flags0 & k_Feat_EffectGiveMaps_Bit) != 0; }
    bool HasEffectIncreaseHitPoints() const { return (m_flags0 & k_Feat_EffectIncreaseHitPoints_Bit) != 0; }
    bool GetEffectIncreaseHitPoints(sint32 & value) const
    {
        if (m_flags0 & k_Feat_EffectIncreaseHitPoints_Bit)
        {
            value = m_EffectIncreaseHitPointsValue;
        }
        return (m_flags0 & k_Feat_EffectIncreaseHitPoints_Bit) != 0;
    }
    bool HasEffectScriptedTurn() const { return (m_flags0 & k_Feat_EffectScriptedTurn_Bit) != 0; }
    bool GetEffectScriptedTurn(char const * & value) const
    {
        if (m_flags0 & k_Feat_EffectScriptedTurn_Bit)
        {
            value = m_EffectScriptedTurnValue;
        }
        return (m_flags0 & k_Feat_EffectScriptedTurn_Bit) != 0;
    }
    bool HasEffectScriptedCity() const { return (m_flags0 & k_Feat_EffectScriptedCity_Bit) != 0; }
    bool GetEffectScriptedCity(char const * & value) const
    {
        if (m_flags0 & k_Feat_EffectScriptedCity_Bit)
        {
            value = m_EffectScriptedCityValue;
        }
        return (m_flags0 & k_Feat_EffectScriptedCity_Bit) != 0;
    }
    sint32 GetExcludeAdvanceIndex(sint32 index) const;
    const AdvanceRecord * GetExcludeAdvance(sint32 index) const;
    sint32 GetNumExcludeAdvance() const { return m_numExcludeAdvance;}
    sint32 GetExcludeWonderIndex(sint32 index) const;
    const WonderRecord * GetExcludeWonder(sint32 index) const;
    sint32 GetNumExcludeWonder() const { return m_numExcludeWonder;}
    sint32 GetExcludeFeatIndex(sint32 index) const;
    const FeatRecord * GetExcludeFeat(sint32 index) const;
    sint32 GetNumExcludeFeat() const { return m_numExcludeFeat;}
    sint32 GetGovernmentsModifiedIndex(sint32 index) const;
    const GovernmentRecord * GetGovernmentsModified(sint32 index) const;
    sint32 GetNumGovernmentsModified() const { return m_numGovernmentsModified;}
    bool HasExcludeFunction() const { return (m_flags0 & k_Feat_ExcludeFunction_Bit) != 0; }
    bool GetExcludeFunction(char const * & value) const
    {
        if (m_flags0 & k_Feat_ExcludeFunction_Bit)
        {
            value = m_ExcludeFunctionValue;
        }
        return (m_flags0 & k_Feat_ExcludeFunction_Bit) != 0;
    }
    sint32 GetCancelAdvanceIndex(sint32 index) const;
    const AdvanceRecord * GetCancelAdvance(sint32 index) const;
    sint32 GetNumCancelAdvance() const { return m_numCancelAdvance;}
    sint32 GetCancelWonderIndex(sint32 index) const;
    const WonderRecord * GetCancelWonder(sint32 index) const;
    sint32 GetNumCancelWonder() const { return m_numCancelWonder;}
    sint32 GetCancelFeatIndex(sint32 index) const;
    const FeatRecord * GetCancelFeat(sint32 index) const;
    sint32 GetNumCancelFeat() const { return m_numCancelFeat;}
    bool HasCancelFunction() const { return (m_flags0 & k_Feat_CancelFunction_Bit) != 0; }
    bool GetCancelFunction(char const * & value) const
    {
        if (m_flags0 & k_Feat_CancelFunction_Bit)
        {
            value = m_CancelFunctionValue;
        }
        return (m_flags0 & k_Feat_CancelFunction_Bit) != 0;
    }
    bool HasBuilding() const { return (m_flags0 & k_Feat_Building_Bit) != 0; }
    bool GetBuilding(const BuildingFeat *&ptr) const
    {
        ptr = (m_flags0 & k_Feat_Building_Bit) ? &m_BuildingValue : NULL;
        return (m_flags0 & k_Feat_Building_Bit) != 0;
    }
    const BuildingFeat * GetBuildingPtr() const
    {
        return (m_flags0 & k_Feat_Building_Bit) ? &m_BuildingValue : NULL;
    }
    bool HasMinimumSizeOfCiv() const { return (m_flags0 & k_Feat_MinimumSizeOfCiv_Bit) != 0; }
    bool GetMinimumSizeOfCiv(sint32 & value) const
    {
        if (m_flags0 & k_Feat_MinimumSizeOfCiv_Bit)
        {
            value = m_MinimumSizeOfCivValue;
        }
        return (m_flags0 & k_Feat_MinimumSizeOfCiv_Bit) != 0;
    }
    bool HasTileImp() const { return (m_flags0 & k_Feat_TileImp_Bit) != 0; }
    bool GetTileImp(const InfrastructureFeat *&ptr) const
    {
        ptr = (m_flags0 & k_Feat_TileImp_Bit) ? &m_TileImpValue : NULL;
        return (m_flags0 & k_Feat_TileImp_Bit) != 0;
    }
    const InfrastructureFeat * GetTileImpPtr() const
    {
        return (m_flags0 & k_Feat_TileImp_Bit) ? &m_TileImpValue : NULL;
    }
    sint32 GetGrantAdvanceIndex(sint32 index) const;
    const AdvanceRecord * GetGrantAdvance(sint32 index) const;
    sint32 GetNumGrantAdvance() const { return m_numGrantAdvance;}
    bool GetHasGovernmentsModified() const { return m_hasGovernmentsModified; }
    sint32 GenericGetNumGovernmentsModified() const { return m_numGovernmentsModified; }
    sint32 GenericGetGovernmentsModifiedIndex(sint32 index) const { return GetGovernmentsModifiedIndex(index); }

}; /* FeatRecord */

struct FeatRecordAccessorInfo
{
    FeatRecord::IntAccessor        m_intAccessor;
    FeatRecord::BoolAccessor       m_boolAccessor;
    FeatRecord::FloatAccessor      m_floatAccessor;
    FeatRecord::BitIntAccessor     m_bitIntAccessor;
    FeatRecord::BitFloatAccessor   m_bitFloatAccessor;
    FeatRecord::IntArrayAccessor   m_intArrayAccessor;
    FeatRecord::FloatArrayAccessor m_floatArrayAccessor;
};

extern FeatRecordAccessorInfo      g_FeatRecord_Accessors[];
extern CTPDatabase<FeatRecord> *   g_theFeatDB;

extern const char * g_Feat_Tokens[];

#endif
