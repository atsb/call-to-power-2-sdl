
/*
 * DO NOT EDIT THIS FILE!
 * It is generated automatically by ctpdb
 */

#if defined(HAVE_PRAGMA_ONCE)
#pragma once
#endif

#ifndef CIVILISATION_RECORD_H__
#define CIVILISATION_RECORD_H__

class CivilisationRecord;

#include "CTPDatabase.h"
#include "CTPRecord.h"
class CivArchive;
class CityStyleRecord;
class MapIconRecord;
class PersonalityRecord;

#define k_Num_CivilisationRecord_Tokens 55

//
// m_flags0: Civilisation
#define k_Civilisation_IsCapital_Bit             0x00000001
#define k_Civilisation_NationUnitFlag_Bit        0x00000002
#define k_Civilisation_OffenseBonusLand_Bit      0x00000004
#define k_Civilisation_OffenseBonusWater_Bit     0x00000008
#define k_Civilisation_OffenseBonusAir_Bit       0x00000010
#define k_Civilisation_LowerCrime_Bit            0x00000020
#define k_Civilisation_LowerPeaceMovement_Bit    0x00000040
#define k_Civilisation_GoldPerCitizen_Bit        0x00000080
#define k_Civilisation_SciencePerPop_Bit         0x00000100
#define k_Civilisation_ReduceReadinessCost_Bit   0x00000200
#define k_Civilisation_GoldPerWaterTradeRoute_Bit 0x00000400
#define k_Civilisation_GoldPerTelevision_Bit     0x00000800
#define k_Civilisation_GoldPerInternationalTradeRoute_Bit 0x00001000
#define k_Civilisation_AllBoatsDeepWater_Bit     0x00002000
#define k_Civilisation_DecreaseMaintenance_Bit   0x00004000
#define k_Civilisation_PreventConversion_Bit     0x00008000
#define k_Civilisation_ProtectFromBarbarians_Bit 0x00010000
#define k_Civilisation_PollutionPercent_Bit      0x00020000
#define k_Civilisation_PollutionAmount_Bit       0x00040000
#define k_MAX_CityName                       500

class CivilisationRecord : public CTPRecord
{
public:
    typedef sint32 (CivilisationRecord::*IntAccessor)() const;
    typedef bool   (CivilisationRecord::*BoolAccessor)() const;
    typedef double (CivilisationRecord::*FloatAccessor)() const ;
    typedef bool   (CivilisationRecord::*BitIntAccessor)(sint32 &val) const;
    typedef bool   (CivilisationRecord::*BitFloatAccessor)(double &val) const;
    typedef sint32 (CivilisationRecord::*IntArrayAccessor)(sint32 index) const;
    typedef double (CivilisationRecord::*FloatArrayAccessor)(sint32 index) const;

private:
    uint32 m_flags0;
    sint32            m_SingularCivName;
    sint32            m_PluralCivName;
    sint32            m_CountryName;
    sint32            m_LeaderNameMale;
    sint32            m_LeaderNameFemale;
    sint32            m_EmissaryPhotoMale;
    sint32            m_EmissaryPhotoFemale;
    sint32            m_PersonalityDescription;
    sint32            m_PersonalityMale; // Index into Personality database
    sint32            m_PersonalityFemale; // Index into Personality database
    sint32            m_Parchment;
    sint32            m_Capital;
    sint32            m_CityStyle; // Index into CityStyle database
    sint32            m_CityName[k_MAX_CityName];
    sint32            m_numCityName;
    sint32            m_NationUnitFlagValue; // Index into MapIcon database
    sint32            m_HappyInc;
    sint32            m_ProductionBonus;
    sint32            m_FoodBonus;
    sint32            m_CommerceBonus;
    sint32            m_ScienceBonus;
    sint32            m_IncreaseBoatMovement;
    sint32            m_IncreaseHp;
    double            m_OffenseBonusLandValue;
    double            m_OffenseBonusWaterValue;
    double            m_OffenseBonusAirValue;
    double            m_LowerCrimeValue;
    double            m_LowerPeaceMovementValue;
    sint32            m_GoldPerCitizenValue;
    double            m_SciencePerPopValue;
    sint32            m_ReduceReadinessCostValue;
    sint32            m_GoldPerWaterTradeRouteValue;
    sint32            m_GoldPerTelevisionValue;
    sint32            m_GoldPerInternationalTradeRouteValue;
    sint32            m_DecreaseMaintenanceValue;
    double            m_PollutionPercentValue;
    double            m_PollutionAmountValue;
    bool m_hasGovernmentsModified; // GovMod specific flag

public:
    CivilisationRecord() { Init(); };
    CivilisationRecord(CivArchive &archive) { Serialize(archive); };
    CivilisationRecord(CivilisationRecord const & rval) { Init(); *this = rval; }
    ~CivilisationRecord();
    CivilisationRecord const & operator = (CivilisationRecord const & rval);

    void Init();
    void Serialize(CivArchive &archive);

    void CheckRequiredFields(DBLexer *lex);
    sint32 Parse(DBLexer *lex, sint32 numRecords);

    void ResolveDBReferences();
    void Merge(const CivilisationRecord & rval);

    sint32 GetSingularCivName() const { return m_SingularCivName; }
    sint32 GetPluralCivName() const { return m_PluralCivName; }
    sint32 GetCountryName() const { return m_CountryName; }
    sint32 GetLeaderNameMale() const { return m_LeaderNameMale; }
    sint32 GetLeaderNameFemale() const { return m_LeaderNameFemale; }
    sint32 GetEmissaryPhotoMale() const { return m_EmissaryPhotoMale; }
    sint32 GetEmissaryPhotoFemale() const { return m_EmissaryPhotoFemale; }
    sint32 GetPersonalityDescription() const { return m_PersonalityDescription; }
    sint32           GetPersonalityMaleIndex() const { return m_PersonalityMale; }
    PersonalityRecord const * GetPersonalityMale() const;
    sint32           GetPersonalityFemaleIndex() const { return m_PersonalityFemale; }
    PersonalityRecord const * GetPersonalityFemale() const;
    sint32 GetParchment() const { return m_Parchment; }
    sint32 GetCapital() const { return m_Capital; }
    bool GetIsCapital() const { return (m_flags0 & k_Civilisation_IsCapital_Bit) != 0; }
    sint32           GetCityStyleIndex() const { return m_CityStyle; }
    CityStyleRecord const * GetCityStyle() const;
sint32     GetCityName(sint32 index) const;
    sint32 GetNumCityName() const { return m_numCityName;}
    bool HasNationUnitFlag() const { return (m_flags0 & k_Civilisation_NationUnitFlag_Bit) != 0; }
    bool GetNationUnitFlagIndex(sint32 & index) const
    {
        index = (m_flags0 & k_Civilisation_NationUnitFlag_Bit) ? m_NationUnitFlagValue : -1;
        return (m_flags0 & k_Civilisation_NationUnitFlag_Bit) != 0;
    }
    bool GetNationUnitFlag(const MapIconRecord * & rec) const;
    const MapIconRecord * GetNationUnitFlagPtr() const;
    sint32 GetHappyInc() const { return m_HappyInc; }
    sint32 GetProductionBonus() const { return m_ProductionBonus; }
    sint32 GetFoodBonus() const { return m_FoodBonus; }
    sint32 GetCommerceBonus() const { return m_CommerceBonus; }
    sint32 GetScienceBonus() const { return m_ScienceBonus; }
    sint32 GetIncreaseBoatMovement() const { return m_IncreaseBoatMovement; }
    sint32 GetIncreaseHp() const { return m_IncreaseHp; }
    bool HasOffenseBonusLand() const { return (m_flags0 & k_Civilisation_OffenseBonusLand_Bit) != 0; }
    bool GetOffenseBonusLand(double & value) const
    {
        if (m_flags0 & k_Civilisation_OffenseBonusLand_Bit)
        {
            value = m_OffenseBonusLandValue;
        }
        return (m_flags0 & k_Civilisation_OffenseBonusLand_Bit) != 0;
    }
    bool HasOffenseBonusWater() const { return (m_flags0 & k_Civilisation_OffenseBonusWater_Bit) != 0; }
    bool GetOffenseBonusWater(double & value) const
    {
        if (m_flags0 & k_Civilisation_OffenseBonusWater_Bit)
        {
            value = m_OffenseBonusWaterValue;
        }
        return (m_flags0 & k_Civilisation_OffenseBonusWater_Bit) != 0;
    }
    bool HasOffenseBonusAir() const { return (m_flags0 & k_Civilisation_OffenseBonusAir_Bit) != 0; }
    bool GetOffenseBonusAir(double & value) const
    {
        if (m_flags0 & k_Civilisation_OffenseBonusAir_Bit)
        {
            value = m_OffenseBonusAirValue;
        }
        return (m_flags0 & k_Civilisation_OffenseBonusAir_Bit) != 0;
    }
    bool HasLowerCrime() const { return (m_flags0 & k_Civilisation_LowerCrime_Bit) != 0; }
    bool GetLowerCrime(double & value) const
    {
        if (m_flags0 & k_Civilisation_LowerCrime_Bit)
        {
            value = m_LowerCrimeValue;
        }
        return (m_flags0 & k_Civilisation_LowerCrime_Bit) != 0;
    }
    bool HasLowerPeaceMovement() const { return (m_flags0 & k_Civilisation_LowerPeaceMovement_Bit) != 0; }
    bool GetLowerPeaceMovement(double & value) const
    {
        if (m_flags0 & k_Civilisation_LowerPeaceMovement_Bit)
        {
            value = m_LowerPeaceMovementValue;
        }
        return (m_flags0 & k_Civilisation_LowerPeaceMovement_Bit) != 0;
    }
    bool HasGoldPerCitizen() const { return (m_flags0 & k_Civilisation_GoldPerCitizen_Bit) != 0; }
    bool GetGoldPerCitizen(sint32 & value) const
    {
        if (m_flags0 & k_Civilisation_GoldPerCitizen_Bit)
        {
            value = m_GoldPerCitizenValue;
        }
        return (m_flags0 & k_Civilisation_GoldPerCitizen_Bit) != 0;
    }
    bool HasSciencePerPop() const { return (m_flags0 & k_Civilisation_SciencePerPop_Bit) != 0; }
    bool GetSciencePerPop(double & value) const
    {
        if (m_flags0 & k_Civilisation_SciencePerPop_Bit)
        {
            value = m_SciencePerPopValue;
        }
        return (m_flags0 & k_Civilisation_SciencePerPop_Bit) != 0;
    }
    bool HasReduceReadinessCost() const { return (m_flags0 & k_Civilisation_ReduceReadinessCost_Bit) != 0; }
    bool GetReduceReadinessCost(sint32 & value) const
    {
        if (m_flags0 & k_Civilisation_ReduceReadinessCost_Bit)
        {
            value = m_ReduceReadinessCostValue;
        }
        return (m_flags0 & k_Civilisation_ReduceReadinessCost_Bit) != 0;
    }
    bool HasGoldPerWaterTradeRoute() const { return (m_flags0 & k_Civilisation_GoldPerWaterTradeRoute_Bit) != 0; }
    bool GetGoldPerWaterTradeRoute(sint32 & value) const
    {
        if (m_flags0 & k_Civilisation_GoldPerWaterTradeRoute_Bit)
        {
            value = m_GoldPerWaterTradeRouteValue;
        }
        return (m_flags0 & k_Civilisation_GoldPerWaterTradeRoute_Bit) != 0;
    }
    bool HasGoldPerTelevision() const { return (m_flags0 & k_Civilisation_GoldPerTelevision_Bit) != 0; }
    bool GetGoldPerTelevision(sint32 & value) const
    {
        if (m_flags0 & k_Civilisation_GoldPerTelevision_Bit)
        {
            value = m_GoldPerTelevisionValue;
        }
        return (m_flags0 & k_Civilisation_GoldPerTelevision_Bit) != 0;
    }
    bool HasGoldPerInternationalTradeRoute() const { return (m_flags0 & k_Civilisation_GoldPerInternationalTradeRoute_Bit) != 0; }
    bool GetGoldPerInternationalTradeRoute(sint32 & value) const
    {
        if (m_flags0 & k_Civilisation_GoldPerInternationalTradeRoute_Bit)
        {
            value = m_GoldPerInternationalTradeRouteValue;
        }
        return (m_flags0 & k_Civilisation_GoldPerInternationalTradeRoute_Bit) != 0;
    }
    bool GetAllBoatsDeepWater() const { return (m_flags0 & k_Civilisation_AllBoatsDeepWater_Bit) != 0; }
    bool HasDecreaseMaintenance() const { return (m_flags0 & k_Civilisation_DecreaseMaintenance_Bit) != 0; }
    bool GetDecreaseMaintenance(sint32 & value) const
    {
        if (m_flags0 & k_Civilisation_DecreaseMaintenance_Bit)
        {
            value = m_DecreaseMaintenanceValue;
        }
        return (m_flags0 & k_Civilisation_DecreaseMaintenance_Bit) != 0;
    }
    bool GetPreventConversion() const { return (m_flags0 & k_Civilisation_PreventConversion_Bit) != 0; }
    bool GetProtectFromBarbarians() const { return (m_flags0 & k_Civilisation_ProtectFromBarbarians_Bit) != 0; }
    bool HasPollutionPercent() const { return (m_flags0 & k_Civilisation_PollutionPercent_Bit) != 0; }
    bool GetPollutionPercent(double & value) const
    {
        if (m_flags0 & k_Civilisation_PollutionPercent_Bit)
        {
            value = m_PollutionPercentValue;
        }
        return (m_flags0 & k_Civilisation_PollutionPercent_Bit) != 0;
    }
    bool HasPollutionAmount() const { return (m_flags0 & k_Civilisation_PollutionAmount_Bit) != 0; }
    bool GetPollutionAmount(double & value) const
    {
        if (m_flags0 & k_Civilisation_PollutionAmount_Bit)
        {
            value = m_PollutionAmountValue;
        }
        return (m_flags0 & k_Civilisation_PollutionAmount_Bit) != 0;
    }
    bool GetHasGovernmentsModified() const { return m_hasGovernmentsModified; }
    sint32 GenericGetNumGovernmentsModified() const { return 0; }
    sint32 GenericGetGovernmentsModifiedIndex(sint32 index) const { return -1; }

}; /* CivilisationRecord */

struct CivilisationRecordAccessorInfo
{
    CivilisationRecord::IntAccessor        m_intAccessor;
    CivilisationRecord::BoolAccessor       m_boolAccessor;
    CivilisationRecord::FloatAccessor      m_floatAccessor;
    CivilisationRecord::BitIntAccessor     m_bitIntAccessor;
    CivilisationRecord::BitFloatAccessor   m_bitFloatAccessor;
    CivilisationRecord::IntArrayAccessor   m_intArrayAccessor;
    CivilisationRecord::FloatArrayAccessor m_floatArrayAccessor;
};

extern CivilisationRecordAccessorInfo      g_CivilisationRecord_Accessors[];
extern CTPDatabase<CivilisationRecord> *   g_theCivilisationDB;

extern const char * g_Civilisation_Tokens[];

#endif
