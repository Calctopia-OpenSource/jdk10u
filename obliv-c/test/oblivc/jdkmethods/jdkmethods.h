/*
 * Copyright (c) 2021 Calctopia and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.  Oracle designates this
 * particular file as subject to the "Classpath" exception as provided
 * by Oracle in the LICENSE file that accompanied this code.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

typedef struct protocolIO64
{ 
  long long result;
  long long input;
  bool partySetInput;
  int party;
} protocolIO64;

void goadd(void* args);

#define MINUSTHREE 0xC008000000000000
#define MINUSTWO 0xC000000000000000
#define MINUSONE 0xBFF0000000000000
#define MINUSHALF 0xBFE0000000000000
#define MINUSQUARTER 0xBFD0000000000000
#define MINUSZERO 0x8000000000000000
#define ZERO 0x0000000000000000
#define HALF 0x3FE0000000000000
#define ONE 0x3FF0000000000000
#define ONETENTH  0x3FB999999999999A //0.1
#define ONEHALF 0x3FF8000000000000
#define TWO 0x4000000000000000
#define THREE 0x4008000000000000
#define FOUR 0x4010000000000000
#define FIVE 0x4014000000000000
#define SIX 0x4018000000000000
#define SEVEN 0x401C000000000000
#define EIGHT 0x4020000000000000
#define TEN 0x4024000000000000
#define TWELVE 0x4028000000000000
#define SIXTEEN 0x4030000000000000
#define F_PI 0x400921FB54442D18
#define TWO_TO_24TH 0x4170000000000000
#define HUNDRETH 0x4059000000000000
#define Q1 0xBFA1110CFFFF82DD  //	Q1 = -3.3333212137e-2 /* -0x888868.0p-28 */
#define Q2 0x3F59E6020000CF03  //   Q2 =  1.5807170421e-3 /*  0xcf3010.0p-33 */
#define SCdEpsilon  0x3E7AD7F29ABCAF48 //1.0E-7
#define YEAR  0x4076D00000000000 //365
#define ONEPERCENT 0x3F847AE147AE147B //0.01
#define TWOPOWSEVEN 0x4060000000000000 //128
#define ZEROSIXTWOFIVE 0x3FE4000000000000 //0.625
#define PIO4 0x3FE921FB54442D18 // 7.853981633974483096157E-1
#define MAXLOG 0x40862E42FEFA39EF //7.09782712893383996843E2 == log(2**1024)
#define MINLOG 0xc0874910d52d3052 // log(2**-1074) = - -7.44440071921381262314E2
#define LOGE2 0x3FF71547652B82FE // 1,4426950408889634073599 == 1/log(2)
#define NAN 0x0000000000000000 // 0.0
#define INFINITY 0x7FEFFFFFFFFFFFFF // 1.79769313486231570815E308 == 2**1024*(1-MACHEP) 
#define MINUSINFINITY  0xFFEFFFFFFFFFFFFF //-1.79769313486231570815E308
#define MOREBITS 0x3C91A62633145C07 //6.123233995736765886130E-17
#define DBL_EPSILON 0x3CB0000000000000 //2,2204460492503131E-16
#define LOG2E 0x3FF71547652B82FE	//1.442695040888963407 == log2( e )

#define MAXNUMF  0x7FEFFFFFFFFFFFFF // DBL_MAX == 1.7976931348623157E+308
#define minusMAXNUMF  0xFFEFFFFFFFFFFFFF //-1.7976931348623157E+308

#define MAX_STR_LENGTH 255

#define LIT64( a ) a##LL

typedef unsigned int bits32;

typedef obliv unsigned long long obits64;
typedef obliv unsigned long long olong;
typedef obliv unsigned long long oint64;
typedef obliv signed long long osbits64;
typedef obliv unsigned long long ofloat64;

typedef obliv bool oflag;
typedef obliv signed char oint8;
typedef obliv int oint16;
typedef obliv unsigned int oint32;
typedef obliv unsigned int ofloat32;
typedef obliv unsigned int obits32;
typedef obliv signed int osbits32;
typedef obliv unsigned short int obits16;
typedef obliv int oint;
typedef obliv unsigned char obyte;

// From SoftFloat
//ofloat64 oint32_to_float64( oint32 a ) obliv;
ofloat64 oint32_to_float64( osbits32 a ) obliv;
ofloat32 oint64_to_float32( oint64 a ) obliv;
ofloat64 oint64_to_float64( osbits64 a ) obliv;
oint64 float32_to_int64( ofloat32 a ) obliv;
oint64 float32_to_int64_round_to_zero( ofloat32 a ) obliv;
ofloat64 float32_to_float64( ofloat32 a ) obliv;
oint32 float64_to_oint32( ofloat64 a ) obliv;
oint32 float64_to_oint32_round_to_zero( ofloat64 a ) obliv;
oint64 float64_to_oint64( ofloat64 a ) obliv;
oint64 float64_to_oint64_round_to_zero( ofloat64 a ) obliv;
ofloat32 float64_to_float32( ofloat64 a ) obliv;
ofloat64 float64_round_to_int( ofloat64 a ) obliv;
oflag extractFloat64Sign( ofloat64 a ) obliv;

//yet to be implemented
ofloat64 float64_roundf( ofloat64 a ) obliv;

ofloat64 float64_add( ofloat64 a, ofloat64 b ) obliv;
ofloat64 float64_sub( ofloat64 a, ofloat64 b ) obliv;
ofloat64 float64_mul( ofloat64 a, ofloat64 b ) obliv;
ofloat64 float64_div( ofloat64 a, ofloat64 b ) obliv;
ofloat64 float64_rem( ofloat64 a, ofloat64 b ) obliv;
ofloat64 float64_sqrt( ofloat64 a ) obliv;
oflag float64_eq( ofloat64 a, ofloat64 b ) obliv;
oflag float64_le( ofloat64 a, ofloat64 b ) obliv;
oflag float64_lt( ofloat64 a, ofloat64 b ) obliv;

obits32 power2(obits32 exp) obliv;
obits64 power2_64 (obits64 exp) obliv;

// Derived from SoftFloat
oflag float64_neq(ofloat64 a, ofloat64 b ) obliv;
oflag float64_ge( ofloat64 a, ofloat64 b ) obliv;
oflag float64_gt( ofloat64 a, ofloat64 b ) obliv;

// Derived from other libraries (mostly musl)
ofloat64 float64_abs( ofloat64 a ) obliv;
ofloat64 float64_fmaxf( ofloat64 a, ofloat64 b ) obliv;
ofloat64 float64_ceil( ofloat64 a ) obliv;
ofloat64 float64_floor( ofloat64 a ) obliv;
ofloat64 float64_tgammaf( ofloat64 a ) obliv;
ofloat64 float64_lgammaf( ofloat64 a ) obliv;
ofloat64 float64_fmodf( ofloat64 a, ofloat64 b ) obliv;
ofloat64 float64_modff(ofloat64 x, ofloat64 *iptr) obliv;
ofloat64 float64_exp2f(ofloat64 x) obliv;
ofloat64 float64_log2f(ofloat64 x) obliv;
ofloat64 float64_atan2f(ofloat64 x, ofloat64 y) obliv;
ofloat64 ScBesselj64f(ofloat64 x, ofloat64 n) obliv;
ofloat64 ScBessely64f(ofloat64 x, ofloat64 n) obliv;
ofloat64 Factorial64f(ofloat64 x) obliv;
ofloat64 ScBesseli64f(ofloat64 x, ofloat64 n) obliv;
ofloat64 ScBesselk64f(ofloat64 x, ofloat64 n) obliv;
ofloat64 float64_erff(ofloat64 x) obliv;
ofloat64 float64_erfcf(ofloat64 x) obliv;
oint float64_ilogbf(ofloat64 x) obliv;
ofloat64 float64_logbf(ofloat64 x) obliv;
ofloat64 float64_rintf(ofloat64 x) obliv;
ofloat64 float64_truncf(ofloat64 x) obliv;

ofloat64 float64_logf( ofloat64 a ) obliv;
ofloat64 float64_log10f (ofloat64 x) obliv;
ofloat64 float64_log1pf( ofloat64 a ) obliv;
ofloat64 float64_powf( ofloat64 a , ofloat64 b ) obliv;
ofloat64 float64_expf( ofloat64 a ) obliv;
ofloat64 float64_expm1f( ofloat64 a ) obliv;
ofloat64 float64_ldexpf(ofloat64 z, oint k) obliv;

// Derived from (OO.o)
oflag approxEqual64f( ofloat64 a, ofloat64 b ) obliv;
ofloat64 approxFloor64f( ofloat64 a ) obliv;
ofloat64 Floor64f(ofloat64 x) obliv;

// Trigs.
ofloat64 float64_sinf( ofloat64 a) obliv;
ofloat64 float64_cosf( ofloat64 a) obliv;
ofloat64 float64_tanf( ofloat64 x ) obliv;
ofloat64 float64_cotf( ofloat64 x ) obliv;
ofloat64 float64_asinhf( ofloat64 a) obliv;
ofloat64 float64_acoshf( ofloat64 a) obliv;
ofloat64 float64_atanhf( ofloat64 a) obliv;
ofloat64 float64_asinf( ofloat64 a) obliv;
ofloat64 float64_acosf( ofloat64 a) obliv;
ofloat64 float64_atanf( ofloat64 x ) obliv;
ofloat64 float64_acosf( ofloat64 a) obliv;
ofloat64 float64_sinhf( ofloat64 a) obliv;
ofloat64 float64_coshf( ofloat64 a) obliv;
ofloat64 float64_tanhf( ofloat64 a) obliv;

//Shared functions between financial and math
ofloat64 Round64f(ofloat64 fValue) obliv;

//Shared functions between engineering64 and math64
ofloat64 Pow10Exp64( ofloat64 fVal, oint nExp ) obliv;

//Shared functions between statistical and math
ofloat64 rtl_math_erf_rd64f( ofloat64 x ) obliv;
ofloat64 rtl_math_erfc_rd64f( ofloat64 x ) obliv;

//imported from float32
oflag IsLeapYear( oint n ) obliv;
oflag IsNotLeapYear( oint n ) obliv;
void DaysToDate(oint nDays, oint *rDay, oint* rMonth, oint* rYear ) obliv;
oint DateToDays_new(oint nDay, oint nMonth, oint nYear) obliv;
oint DateToDays_( oint nDay, oint nMonth, oint nYear ) obliv;
oint DaysInMonth_( oint nMonth, oint nYear ) obliv;
oint GetNullDate_new() obliv;
oint GetNullDate(void) obliv;
oint omin(oint a, oint b) obliv;
void ScaDate_ (oint nNullDate, oint nDate, oint nBase, oint *nOrigDay, oint *nMonth, oint *nYear, oint *bLastDayMode, oint *bLastDay, oint *b30Days, oint *bUSMode, oint *nDay) obliv;
void ScaDate2( oint nNullDate, oint nDate, oint nBase, oint *bLastDayMode, oint *bLastDay, oint *b30Days, oint *bUSMode) obliv;
void addMonths (oint b30Days, oint bLastDay, oint *nDay, oint nOrigDay, oint *nMonth, oint nMonthCount, oint *year) obliv;
void setDay (oint nOrigDay, oint nMonth, oint nYear, oint bLastDay, oint b30Days, oint *nDay) obliv;
oint checklessthan(oint aYear,oint bYear,oint aMonth,oint bMonth,oint anDay,oint bnDay,oint abLastDay,oint bbLastDay,oint anOrigDay,oint bnOrigDay) obliv;
oint lcl_GetCouppcd(oint nNullDate, oint nSettle, oint nMat, oint nFreq, oint nBase) obliv;
oint lcl_GetCoupncd(oint nNullDate, oint nSettle, oint nMat, oint nFreq, oint nBase) obliv;
oint getDaysInMonthRange( oint nFrom, oint nTo, oint b30Days, oint year) obliv;
oint GetDaysInYears_( oint nYear1, oint nYear2 ) obliv;
oint GetDaysInYear( oint nNullDate, oint nDate, oint nMode ) obliv;
oint getDaysInYearRange( oint nFrom, oint nTo, oint b30Days ) obliv;
oint getDiff(oint rFrom, oint rTo, oint fDay, oint fMonth, oint fYear, oint fbLastDayMode, oint fbLastDay, oint fb30Days, oint fbUSMode, oint fnDay, oint tDay, oint tMonth, oint tYear, oint tbLastDayMode, oint tbLastDay, oint tb30Days, oint tbUSMode, oint tnDay) obliv;
oint lcl_Getcoupdaybs(oint nNullDate, oint nSettle, oint nMat, oint nFreq, oint nBase) obliv;
oint lcl_Getcoupdaybs_new(oint nNullDate,oint nSettle,oint nMat,oint nFreq,oint nBase) obliv;
oint lcl_Getcoupdays(oint nNullDate, oint nSettle, oint nMat, oint nFreq, oint nBase) obliv;
oint lcl_Getcoupdays_new(oint nNullDate,oint nSettle, oint nMat,oint nFreq,oint nBase) obliv;
oint lcl_Getcoupnum(oint nNullDate,oint nSettle,oint nMat,oint nFreq) obliv;
void DaysToDate_new( oint nDays, oint *rDay, oint* rMonth, oint* rYear ) obliv;
oint GetDiffDate( oint nNullDate, oint nStartDate, oint nEndDate, oint nMode, oint* pOptDaysIn1stYear ) obliv;
oint GetDiffDate_new( oint nNullDate, oint nStartDate, oint nEndDate, oint nMode, oint* pOptDaysIn1stYear ) obliv;
oint GetDiffDate360_(oint nDay1, oint nMonth1, oint nYear1, oflag bLeapYear1, oint nDay2, oint nMonth2, oint nYear2, oflag bUSAMethod ) obliv;
oint GetDiffDate360( oint nNullDate, oint nDate1, oint nDate2, oflag bUSAMethod ) obliv;
obyte digitToOByte(oint digit) obliv;
oint getTenExp(obyte *strConv, int pos) obliv;
oint getTwoExp(obyte *strConv, int pos) obliv;
oflag checkTwo(obyte *strConv, int pos, obyte a, obyte b) obliv;
oflag checkThree(obyte *strConv, int pos, obyte a, obyte b, obyte c) obliv;
oflag checkThreeNormal(obyte *strConv, int pos, obyte a, obyte b, obyte c) obliv;
oflag checkFour(obyte *strConv, int pos, obyte a, obyte b, obyte c, obyte d) obliv;
oflag checkFive(obyte *strConv, int pos, obyte a, obyte b, obyte c, obyte d, obyte e) obliv;
oflag checkSix(obyte *strConv, int pos, obyte a, obyte b, obyte c, obyte d, obyte e, obyte f) obliv;
oflag checkSeven(obyte *strConv, int pos, obyte a, obyte b, obyte c, obyte d, obyte e, obyte f, obyte g) obliv;
oflag checkEight(obyte *strConv, int pos, obyte a, obyte b, obyte c, obyte d, obyte e, obyte f, obyte g, obyte h) obliv;
oflag checkNine(obyte *strConv, int pos, obyte a, obyte b, obyte c, obyte d, obyte e, obyte f, obyte g, obyte h, obyte i) obliv;
oflag getArabicValue(obyte cChar, oint *rnValue, oflag *rbIsDec) obliv;
obyte getRomanValue(oint id) obliv;
obyte getRomanChar(oint id) obliv;
void appendOByte(obyte* string1, obyte addChar, int maxLen) obliv;
oint getLengthOByteChar(obyte* string, int maxLen) obliv;
void appendOString(obyte* string1, obyte* string2, int maxLen) obliv;
oflag equalsOByteChar(obyte *aFromUnit, obyte *aToUnit) obliv;
oflag obyteEqualsOByte(obyte c, obyte d) obliv;
oflag obyteIsPercentage(obyte c) obliv;
void ostringToUpper(obyte *aString, int maxLen) obliv;
oint obyteGetVal(obyte c) obliv;
oflag obyteIsNum(obyte c) obliv;
oflag obyteIsNotNum(obyte c) obliv;
oflag obyteEqualsD(obyte c) obliv;
oflag obyteEqualsM(obyte c) obliv;
oflag obyteEqualsY(obyte c) obliv;
oflag obyteEqualsMD(obyte c1, obyte c2) obliv;
oflag obyteEqualsYM(obyte c1, obyte c2) obliv;
oflag obyteEqualsYD(obyte c1, obyte c2) obliv;
void numberToOStr(oint nNum, obyte* aRet, int nBase, int maxLen) obliv;
oflag obyteIsImagUnit(obyte c) obliv;
oflag obyteIsComma(obyte c) obliv;
oflag obyteIsImagUnit(obyte c) obliv;
oflag obyteIsExpStart(obyte c) obliv;

//From float32, also needed on float64
oint8 countLeadingZeros32( obits32 a ) obliv;
ofloat32 packFloat32( oflag zSign, oint16 zExp, obits32 zSig ) obliv;
ofloat32 roundAndPackFloat32( oflag zSign, oint16 zExp, obits32 zSig ) obliv;
ofloat32 roundAndPackFloat32_long( oflag zSign, oint16 zExp, obits32 zSig ) obliv;
obits32 extractFloat32Frac( ofloat32 a ) obliv;
oint16 extractFloat32Exp( ofloat32 a ) obliv;
oflag extractFloat32Sign( ofloat32 a ) obliv;
void normalizeFloat32Subnormal( obits32 aSig, oint16 *zExpPtr, obits32 *zSigPtr ) obliv;
ofloat32 float32_expf( ofloat32 a ) obliv;
void setNullOString(obyte *aStr) obliv;
void appendOString(obyte* string1, obyte* string2, int maxLen) obliv;
ofloat32 float32_to_int(ofloat32 a) obliv;

// MAX ITERS from float.h
// WELL-DEFINED MAX ITER DEFINITIONS
#define MAXITER_MONTHS 12
#define MAXITER_MAXYEARS 8100 // 10 // Excel only considers from year 1900 to 10000
#define MAXITER_MAXCOUPS 32400 // 10 // Max number of coupons from 1/1/1900 to 31/12/9999 on a quaterly basis (COUPNUM)

#define MAXITER_GAMMASERIES 10000 // 2
#define MAXITER_GAMMACONTFRACTION 10000 // 4
#define MAXITER_BETACONTFRAC 50000 // 2

#define MAXITER_INVERSEBETA 1000 // 2
#define MAXITER_INVERSEBETA2 500 // 2
#define MAXITER_INVERSECHI 1000 // 2
#define MAXITER_INVERSECHI2 500 // 2
#define MAXITER_INVERSECHISQ 1000 // 2
#define MAXITER_INVERSECHISQ2 500 // 2
#define MAXITER_ITINVERSE 1000 // 2
#define MAXITER_ITINVERSE2 500 // 2
#define MAXITER_INVERSEGAMMA 1000 // 2
#define MAXITER_INVERSEGAMMA2 500 // 2
#define MAXITER_INVERSEF 1000 // 2
#define MAXITER_INVERSEF2 500 // 2
#define MAXITER_RATEITERATION 150 // 5
#define MAXITER_XIRR 50 // 9
#define MAXITER_XIRRSCAN 200 // 5
#define MAXITER_YIELD 100 // 5

// EMPIRICALLY UPPERBOUNDED, LOW VALUE
#define MAXITER_BINOMDISTPMF 1000 // 2 // Difference between trials and number of successes in trials (second - first arguments): negligible when > 1000
#define MAXITER_SCBINOMDIST 1000 // 2  // Idem previous one
#define MAXITER_VARIATIONEN 169 // 5 // On PERMUT, max number of chosen objets in each permutation (second argument)
#define MAXITER_MAXFACT_32 35 // Max factorial with 32 bit precission
#define MAXITER_MAXFACT 170 // Max factorial with 64 bit precission
#define MAXITER_FACTDOUBLE_32 35 // Idem
#define MAXITER_FACTDOUBLE_64 170 // Idem
#define MAXITER_GCD32 190 // Max number of steps for the GCD's Euclidean algorithm is 5 times the number of its digits in base 10: 5*38=190 (32 bit max float == 3.4x10^38)
#define MAXITER_GCD64 1540 // 5*308 == 1540 (64 bit max float == 10^308)
#define MAXITER_iLOGBF32 256 // Ranges by all the exponents, from -128 to 127 , that is, 2^8=256
#define MAXITER_iLOGBF64 2048 // Ranges by all the exponents, from -1023 to 1022, that is, 2^11=2048

// EMPIRICALLY UPPERBOUNDED, VERY HIGH VALUE
#define MAXITER_CRITBINOM 2147483647 // 3 // On CRITBINOM, max number of trials (first argument) is equals to MAX_INT-1
#define MAXITER_CHISQDISTPDF 999999999 // 2 //On CHISQ.DIST, max degree of freedom (10^10-1)
#define MAXITER_JNF_NM1 10000000 // Max order of the BESSELJ function
#define MAXITER_BESSELK 10000000 // Max order of the BESSELK function
#define MAXITER_BESSELI 100 // Max order of the BESSELI function
#define MAXITER_JNF_Q1 10000 // Max iteration within the BESSEL functions (1.0e4f)
#define MAXITER_JNF_Q1_64 1000000000 // Max iteration within the BESSEL functions (1.0e9)
#define MAXITER_COMBINA 2147483646 // On COMBINA, max number chosen

// UNBOUNDED
#define MAXITER_HYPERGEOMETRIC 100 // 2 // On HYPGEOM.DIST, as high as the first argument can get (number of samples in cumulative HYPGEOM)
#define MAXITER_BINOMDISTRANGE_XS 100 // 2 //On BINOM.DIST.RANGE, number of successes in trials
#define MAXITER_BINOMDISTRANGE_XE 100 // 2 //On BINOM.DIST.RANGE, max range of successes in trials
#define MAXITER_POISSONDIST 100 // 2 // On POISSON.DIST, as high as the first argument can get (max number of events)
#define MAXITER_NEGBINOMDIST 100 // 2 // On NEGBINOM.DIST, as high as the first argument can get (max number of failures)
#define MAXITER_MAXPERIODS 1000 // 10 // On CUMPRINC and others, max number of periods to be considered
#define MAXITER_COMBIN 100 // On COMBIN, max number of items in each combination
