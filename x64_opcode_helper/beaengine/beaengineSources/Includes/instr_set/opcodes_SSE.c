/* Copyright 2006-2009, BeatriX
 * File coded by BeatriX
 *
 * This file is part of BeaEngine.
 *
 *    BeaEngine is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU Lesser General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    BeaEngine is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public License
 *    along with BeaEngine.  If not, see <http://www.gnu.org/licenses/>. */

/* ====================================================================
 *      0x 0f 58
 * ==================================================================== */
void __bea_callspec__ addps_VW(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_ADDSD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm64(pMyDisasm);
    }
    /* ========= 0xf3 */
    else if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_ADDSS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm32(pMyDisasm);
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_ADDPD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_ADDPS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f d0
 * ==================================================================== */
void __bea_callspec__ addsubpd_(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+SIMD_FP_PACKED;
        (*pMyDisasm).Instruction.Mnemonic = I_ADDSUBPS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }

    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+SIMD_FP_PACKED;
        (*pMyDisasm).Instruction.Mnemonic = I_ADDSUBPD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 55
 * ==================================================================== */
void __bea_callspec__ andnps_VW(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+LOGICAL_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_ANDNPD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+LOGICAL_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_ANDNPS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 54
 * ==================================================================== */
void __bea_callspec__ andps_VW(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+LOGICAL_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_ANDPD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+LOGICAL_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_ANDPS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 3a 0d
 * ==================================================================== */
void __bea_callspec__ blendpd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_BLENDING_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_BLENDPD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.ImmediatSize = 8;
        XMMregXMMrm(pMyDisasm);
        if (!Security1(pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.EIP_++;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 3a 0c
 * ==================================================================== */
void __bea_callspec__ blendps_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_BLENDING_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_BLENDPS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.ImmediatSize = 8;
        XMMregXMMrm(pMyDisasm);
        if (!Security1(pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.EIP_++;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 15
 * ==================================================================== */
void __bea_callspec__ blendvpd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_BLENDING_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_BLENDVPD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        (*pMyDisasm).Argument3.ArgType = IMPLICIT_ARG+REGISTER_TYPE+SSE_REG+REG0;
        (*pMyDisasm).Argument3.ArgSize = 128;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 14
 * ==================================================================== */
void __bea_callspec__ blendvps_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_BLENDING_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_BLENDVPS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        (*pMyDisasm).Argument3.ArgType = IMPLICIT_ARG+REGISTER_TYPE+SSE_REG+REG0;
        (*pMyDisasm).Argument3.ArgSize = 128;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f c2
 * ==================================================================== */
void __bea_callspec__ cmpps_VW(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    GV.ImmediatSize = 8;
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+COMPARISON_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_CMPSD;
        XMMregXMMrm64(pMyDisasm);
    }
    /* ========== 0xf3 */
    else if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+COMPARISON_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_CMPSS;
        XMMregXMMrm32(pMyDisasm);
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+COMPARISON_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_CMPPD;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+COMPARISON_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_CMPPS;
        XMMregXMMrm(pMyDisasm);
    }
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    if (!Security1(pMyDisasm)) return;
    (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
    (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument3.ArgSize = 8;
    GV.EIP_++;
}


/* ====================================================================
 *      0x 0f 38 f0
 * ==================================================================== */
void __bea_callspec__ crc32_GvEb(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE42_INSTRUCTION+ACCELERATOR_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_CRC32;
        if ((*pMyDisasm).Instruction.OperandSize == 64) {
            (*pMyDisasm).Argument2.ArgSize = 8;
            (*pMyDisasm).Instruction.OperandSize = 8;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.OperandSize = 64;
        }
        else {
            (*pMyDisasm).Argument2.ArgSize = 8;
            (*pMyDisasm).Instruction.OperandSize = 8;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.OperandSize = 32;
        }

        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.EIP_ += GV.DECALAGE_EIP;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 f1
 * ==================================================================== */
void __bea_callspec__ crc32_GvEv(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE42_INSTRUCTION+ACCELERATOR_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_CRC32;

        (*pMyDisasm).Argument2.ArgSize = (*pMyDisasm).Instruction.OperandSize;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);

        if ((*pMyDisasm).Instruction.OperandSize == 16) {
            (*pMyDisasm).Instruction.OperandSize = 32;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.OperandSize = 16;
        }
        else {
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        }
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.EIP_ += GV.DECALAGE_EIP;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 2f
 * ==================================================================== */
void __bea_callspec__ comiss_VW(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+COMPARISON_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_COMISD;
        (*pMyDisasm).Argument1.AccessMode = READ;
        XMMregXMMrm64(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+COMPARISON_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_COMISS;
        (*pMyDisasm).Argument1.AccessMode = READ;
        XMMregXMMrm(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 5a
 * ==================================================================== */
void __bea_callspec__ cvtps2pd_(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_CVTSD2SS;
        XMMregXMMrm64(pMyDisasm);
    }
    /* ========== 0xf3 */
    else if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_CVTSS2SD;
        XMMregXMMrm32(pMyDisasm);
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_CVTPD2PS;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_CVTPS2PD;
        XMMregXMMrm64(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 5b
 * ==================================================================== */
void __bea_callspec__ cvtdq2ps_(PDISASM pMyDisasm)
{
    /* ========== 0xf3 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_CVTTPS2DQ;
        XMMregXMMrm(pMyDisasm);
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_CVTPS2DQ;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_CVTDQ2PS;
        XMMregXMMrm(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 2a
 * ==================================================================== */
void __bea_callspec__ cvtpi2ps_(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_CVTSI2SD;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        (*pMyDisasm).Argument2.ArgSize = (*pMyDisasm).Instruction.OperandSize;
        RegSSE_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_+= GV.DECALAGE_EIP;
    }
    /* ========== 0xf3 */
    else if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_CVTSI2SS;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        (*pMyDisasm).Argument2.ArgSize = (*pMyDisasm).Instruction.OperandSize;
        RegSSE_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_+= GV.DECALAGE_EIP;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_CVTPI2PD;
        XMMregMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_CVTPI2PS;
        XMMregMMrm(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 2d
 * ==================================================================== */
void __bea_callspec__ cvtps2pi_(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_CVTSD2SI;
        MOD_RM_SSE(&(*pMyDisasm).Argument2, pMyDisasm);
        (*pMyDisasm).Argument2.ArgSize = 64;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_+= GV.DECALAGE_EIP;
    }
    /* ========== 0xf3 */
    else if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_CVTSS2SI;
        MOD_RM_SSE(&(*pMyDisasm).Argument2, pMyDisasm);
        (*pMyDisasm).Argument2.ArgSize = 32;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_+= GV.DECALAGE_EIP;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_CVTPD2PI;
        MMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_CVTPS2PI;
        MOD_RM_SSE(&(*pMyDisasm).Argument2, pMyDisasm);
        (*pMyDisasm).Argument2.ArgSize = 64;
        RegMMX_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_+= GV.DECALAGE_EIP;
    }
}


/* ====================================================================
 *      0x 0f 2c
 * ==================================================================== */
void __bea_callspec__ cvttps2pi_(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_CVTTSD2SI;
        MOD_RM_SSE(&(*pMyDisasm).Argument2, pMyDisasm);
        (*pMyDisasm).Argument2.ArgSize = 64;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_+= GV.DECALAGE_EIP;
    }
    /* ========== 0xf3 */
    else if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_CVTTSS2SI;
        MOD_RM_SSE(&(*pMyDisasm).Argument2, pMyDisasm);
        (*pMyDisasm).Argument2.ArgSize = 32;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_+= GV.DECALAGE_EIP;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_CVTTPD2PI;
        MMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_CVTTPS2PI;
        (*pMyDisasm).Argument2.ArgSize = 64;
        MOD_RM_SSE(&(*pMyDisasm).Argument2, pMyDisasm);
        (*pMyDisasm).Argument2.ArgSize = 64;
        RegMMX_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_+= GV.DECALAGE_EIP;
    }
}


/* ====================================================================
 *      0x 0f e6
 * ==================================================================== */
void __bea_callspec__ cvtpd2dq_(PDISASM pMyDisasm)
{
    /* ========== 0xf2 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_CVTPD2DQ;
        XMMregXMMrm(pMyDisasm);
    }
    /* ========== 0xf3 */
    else if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_CVTDQ2PD;
        XMMregXMMrm64(pMyDisasm);
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);

        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_CVTTPD2DQ;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 3a 41
 * ==================================================================== */
void __bea_callspec__ dppd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+DOT_PRODUCT;
        (*pMyDisasm).Instruction.Mnemonic = I_DPPD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.ImmediatSize = 8;
        XMMregXMMrm(pMyDisasm);
        if (!Security1(pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.EIP_++;
    }
    else {
        FailDecode(pMyDisasm);
    }

}

/* ====================================================================
 *      0x 0f 3a 40
 * ==================================================================== */
void __bea_callspec__ dpps_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+DOT_PRODUCT;
        (*pMyDisasm).Instruction.Mnemonic = I_DPPS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.ImmediatSize = 8;
        XMMregXMMrm(pMyDisasm);
        if (!Security1(pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.EIP_++;
    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 5e
 * ==================================================================== */
void __bea_callspec__ divps_VW(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_DIVSD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm64(pMyDisasm);
    }
    /* ========= 0xf3 */
    else if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_DIVSS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm32(pMyDisasm);
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_DIVPD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_DIVPS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 3a 17
 * ==================================================================== */
void __bea_callspec__ extractps_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+INSERTION_EXTRACTION;
        (*pMyDisasm).Instruction.Mnemonic = I_EXTRACTPS;
        GV.ImmediatSize = 8;
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        (*pMyDisasm).Argument1.ArgSize = 32;
        RegSSE_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.EIP_+= GV.DECALAGE_EIP;
        if (!Security1(pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.EIP_++;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 7c
 * ==================================================================== */
void __bea_callspec__ haddpd_VW(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+SIMD_FP_HORIZONTAL;
        (*pMyDisasm).Instruction.Mnemonic = I_HADDPD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+SIMD_FP_HORIZONTAL;
        (*pMyDisasm).Instruction.Mnemonic = I_HADDPS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 7d
 * ==================================================================== */
void __bea_callspec__ hsubpd_VW(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+SIMD_FP_HORIZONTAL;
        (*pMyDisasm).Instruction.Mnemonic = I_HSUBPD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+SIMD_FP_HORIZONTAL;
        (*pMyDisasm).Instruction.Mnemonic = I_HSUBPS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 3a 21
 * ==================================================================== */
void __bea_callspec__ insertps_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+INSERTION_EXTRACTION;
        (*pMyDisasm).Instruction.Mnemonic = I_INSERTPS;
        GV.ImmediatSize = 8;
        XMMregXMMrm32(pMyDisasm);
        if (!Security1(pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.EIP_++;
    }
    else {
        FailDecode(pMyDisasm);
    }
}



/* ====================================================================
 *      0x 0f f0
 * ==================================================================== */
void __bea_callspec__ lddqu_(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+SPECIALIZED_128bits;
        (*pMyDisasm).Instruction.Mnemonic = I_LDDQU;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        if (GV.MOD_ == 3) {
            FailDecode(pMyDisasm);
        }
        (*pMyDisasm).Argument2.ArgSize = 128;
        RegSSE_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_+= GV.DECALAGE_EIP;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f f7
 * ==================================================================== */
void __bea_callspec__ maskmovq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CACHEABILITY_CONTROL;
        (*pMyDisasm).Instruction.Mnemonic = I_MASKMOVDQU;
        XMMregXMMrm(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument3.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
        (*pMyDisasm).Argument3.Memory.BaseRegister = REG7;
        (*pMyDisasm).Argument3.ArgSize = 8; /* don't know */
        (*pMyDisasm).Argument3.AccessMode = WRITE;
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+CACHEABILITY_CONTROL;
        (*pMyDisasm).Instruction.Mnemonic = I_MASKMOVQ;
        MMregMMrm(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument3.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
        (*pMyDisasm).Argument3.Memory.BaseRegister = REG7;
        (*pMyDisasm).Argument3.ArgSize = 8; /* don't know */
        (*pMyDisasm).Argument3.AccessMode = WRITE;
    }
}


/* ====================================================================
 *      0x 0f 5f
 * ==================================================================== */
void __bea_callspec__ maxps_VW(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_MAXSD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm64(pMyDisasm);
    }
    /* ========= 0xf3 */
    else if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_MAXSS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm32(pMyDisasm);
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_MAXPD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_MAXPS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 5d
 * ==================================================================== */
void __bea_callspec__ minps_VW(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_MINSD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm64(pMyDisasm);
    }
    /* ========= 0xf3 */
    else if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_MINSS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm32(pMyDisasm);
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_MINPD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_MINPS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 28
 * ==================================================================== */
void __bea_callspec__ movaps_VW(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
        (*pMyDisasm).Instruction.Mnemonic = I_MOVAPD;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
        (*pMyDisasm).Instruction.Mnemonic = I_MOVAPS;
        XMMregXMMrm(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 29
 * ==================================================================== */
void __bea_callspec__ movaps_WV(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
        (*pMyDisasm).Instruction.Mnemonic = I_MOVAPD;
        XMMrmXMMreg(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
        (*pMyDisasm).Instruction.Mnemonic = I_MOVAPS;
        XMMrmXMMreg(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 16
 * ==================================================================== */
void __bea_callspec__ movhps_VM(PDISASM pMyDisasm)
{
    /* ========= 0xf3 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+DATA_TRANSFER;
        (*pMyDisasm).Instruction.Mnemonic = I_MOVSHDUP;
        XMMregXMMrm64(pMyDisasm);
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
        (*pMyDisasm).Instruction.Mnemonic = I_MOVHPD;
        XMMregXMMrm64(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+DATA_TRANSFER;
        XMMregXMMrm64(pMyDisasm);
        if (GV.MOD_== 0x3) {
            (*pMyDisasm).Instruction.Mnemonic = I_MOVLHPS;
        }
        else {
            (*pMyDisasm).Instruction.Mnemonic = I_MOVHPS;
        }
    }
}


/* ====================================================================
 *      0x 0f 17
 * ==================================================================== */
void __bea_callspec__ movhps_MV(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
        (*pMyDisasm).Instruction.Mnemonic = I_MOVHPD;
        XMMrm64XMMreg(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+DATA_TRANSFER;
        (*pMyDisasm).Instruction.Mnemonic = I_MOVHPS;
        XMMrm64XMMreg(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 12
 * ==================================================================== */
void __bea_callspec__ movlps_VM(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+DATA_TRANSFER;
        (*pMyDisasm).Instruction.Mnemonic = I_MOVDDUP;
        XMMregXMMrm64(pMyDisasm);
    }
    /* ========= 0xf3 */
    else if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+DATA_TRANSFER;
        (*pMyDisasm).Instruction.Mnemonic = I_MOVSLDUP;
        XMMregXMMrm64(pMyDisasm);
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
        (*pMyDisasm).Instruction.Mnemonic = I_MOVLPD;
        XMMregXMMrm64(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+DATA_TRANSFER;
        XMMregXMMrm64(pMyDisasm);
        if (GV.MOD_== 0x3) {
            (*pMyDisasm).Instruction.Mnemonic = I_MOVHLPS;
        }
        else {
            (*pMyDisasm).Instruction.Mnemonic = I_MOVLPS;
        }
    }
}


/* ====================================================================
 *      0x 0f 13
 * ==================================================================== */
void __bea_callspec__ movlps_MV(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
        (*pMyDisasm).Instruction.Mnemonic = I_MOVLPD;
        XMMrm64XMMreg(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+DATA_TRANSFER;
        (*pMyDisasm).Instruction.Mnemonic = I_MOVLPS;
        XMMrm64XMMreg(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 50
 * ==================================================================== */
void __bea_callspec__ movmskps_(PDISASM pMyDisasm)
{
    GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_))) >> 6) & 0x3;
    if (GV.MOD_!= 0x3) {
        FailDecode(pMyDisasm);
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
        (*pMyDisasm).Instruction.Mnemonic = I_MOVMSKPD;
        if ((*pMyDisasm).Archi == 64) {
            (*pMyDisasm).Instruction.OperandSize = 64;
        }
        MOD_RM_SSE(&(*pMyDisasm).Argument2, pMyDisasm);
        (*pMyDisasm).Argument2.ArgSize = 128;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP;
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+DATA_TRANSFER;
        (*pMyDisasm).Instruction.Mnemonic = I_MOVMSKPS;
        if ((*pMyDisasm).Archi == 64) {
            (*pMyDisasm).Instruction.OperandSize = 64;
        }
        MOD_RM_SSE(&(*pMyDisasm).Argument2, pMyDisasm);
        (*pMyDisasm).Argument2.ArgSize = 128;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP;
    }
}


/* ====================================================================
 *      0x 0f 38 2a
 * ==================================================================== */
void __bea_callspec__ movntdqa_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+STREAMING_LOAD;
        (*pMyDisasm).Instruction.Mnemonic = I_MOVNTDQA;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f c3
 * ==================================================================== */
void __bea_callspec__ movnti_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CACHEABILITY_CONTROL;
    (*pMyDisasm).Instruction.Mnemonic = I_MOVNTI;
    EvGv(pMyDisasm);
}


/* ====================================================================
 *      0x 0f 2b
 * ==================================================================== */
void __bea_callspec__ movntps_(PDISASM pMyDisasm)
{
    GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_))) >> 6) & 0x3;
    if (GV.MOD_== 0x3) {
        FailDecode(pMyDisasm);
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CACHEABILITY_CONTROL;
        (*pMyDisasm).Instruction.Mnemonic = I_MOVNTPD;
        XMMrmXMMreg(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CACHEABILITY_CONTROL;
        (*pMyDisasm).Instruction.Mnemonic = I_MOVNTPS;
        XMMrmXMMreg(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f e7
 * ==================================================================== */
void __bea_callspec__ movntq_(PDISASM pMyDisasm)
{
    GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
    if (GV.MOD_== 0x3) {
        FailDecode(pMyDisasm);
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CACHEABILITY_CONTROL;
        (*pMyDisasm).Instruction.Mnemonic = I_MOVNTDQ;
        XMMrmXMMreg(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+CACHEABILITY_CONTROL;
        (*pMyDisasm).Instruction.Mnemonic = I_MOVNTQ;
        XMMrm64XMMreg(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 10
 * ==================================================================== */
void __bea_callspec__ movups_VW(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_MOVSD;
        XMMregXMMrm64(pMyDisasm);
    }
    /* ========= 0xf3 */
    else if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_MOVSS;
        XMMregXMMrm32(pMyDisasm);
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_MOVUPD;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_MOVUPS;
        XMMregXMMrm(pMyDisasm);
    }
}



/* ====================================================================
 *      0x 0f 11
 * ==================================================================== */
void __bea_callspec__ movups_WV(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_MOVSD;
        XMMrm64XMMreg(pMyDisasm);
    }
    /* ========= 0xf3 */
    else if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_MOVSS;
        XMMrm32XMMreg(pMyDisasm);
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_MOVUPD;
        XMMrmXMMreg(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_MOVUPS;
        XMMrmXMMreg(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 3a 42
 * ==================================================================== */
void __bea_callspec__ mpsadbw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+SAD_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_MPSADBW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.ImmediatSize = 8;
        XMMregXMMrm(pMyDisasm);
        if (!Security1(pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.EIP_++;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 59
 * ==================================================================== */
void __bea_callspec__ mulps_VW(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_MULSD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm64(pMyDisasm);
    }
    /* ========== 0xf3 */
    else if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_MULSS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm32(pMyDisasm);
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_MULPD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_MULPS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 56
 * ==================================================================== */
void __bea_callspec__ orps_VW(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+LOGICAL_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_ORPD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+LOGICAL_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_ORPS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 2b
 * ==================================================================== */
void __bea_callspec__ packusdw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PACKUSDW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f d4
 * ==================================================================== */
void __bea_callspec__ paddq_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SIMD128bits;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Mnemonic = I_PADDQ;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Mnemonic = I_PADDQ;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        MMregMMrm(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f e0
 * ==================================================================== */
void __bea_callspec__ pavgb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Mnemonic = I_PAVGB;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Mnemonic = I_PAVGB;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        MMregMMrm(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f e3
 * ==================================================================== */
void __bea_callspec__ pavgw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Mnemonic = I_PAVGW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Mnemonic = I_PAVGW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        MMregMMrm(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 3a 0f
 * ==================================================================== */
void __bea_callspec__ palignr_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Mnemonic = I_PALIGNR;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.ImmediatSize = 8;
        XMMregXMMrm(pMyDisasm);
        if (!Security1(pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.EIP_++;
    }
    else {
        (*pMyDisasm).Instruction.Mnemonic = I_PALIGNR;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.ImmediatSize = 8;
        MMregMMrm(pMyDisasm);
        if (!Security1(pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.EIP_++;
    }
}


/* ====================================================================
 *      0x 0f 38 10
 * ==================================================================== */
void __bea_callspec__ pblendvb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_BLENDING_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Mnemonic = I_PBLENDVB;
        XMMregXMMrm(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        (*pMyDisasm).Argument3.ArgType = IMPLICIT_ARG+SSE_REG+REG0;
        (*pMyDisasm).Argument3.ArgSize = 128;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 3a 0e
 * ==================================================================== */
void __bea_callspec__ pblendw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+SAD_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PBLENDW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        GV.ImmediatSize = 8;
        XMMregXMMrm(pMyDisasm);
        if (!Security1(pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.EIP_++;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 29
 * ==================================================================== */
void __bea_callspec__ pcmpeqq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_EQUALITY;
        (*pMyDisasm).Instruction.Mnemonic = I_PCMPEQQ;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 3a 61
 * ==================================================================== */
void __bea_callspec__ pcmpestri_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE42_INSTRUCTION+COMPARISON_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PCMPESTRI;
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.ImmediatSize = 8;
        XMMregXMMrm(pMyDisasm);
        if (!Security1(pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG1;
        GV.EIP_++;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 3a 60
 * ==================================================================== */
void __bea_callspec__ pcmpestrm_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE42_INSTRUCTION+COMPARISON_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PCMPESTRM;
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.ImmediatSize = 8;
        XMMregXMMrm(pMyDisasm);
        if (!Security1(pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = SSE_REG+REG0;
        GV.EIP_++;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 3a 63
 * ==================================================================== */
void __bea_callspec__ pcmpistri_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE42_INSTRUCTION+COMPARISON_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PCMPISTRI;
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.ImmediatSize = 8;
        XMMregXMMrm(pMyDisasm);
        if (!Security1(pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG1;
        GV.EIP_++;
    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 3a 62
 * ==================================================================== */
void __bea_callspec__ pcmpistrm_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE42_INSTRUCTION+COMPARISON_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PCMPESTRM;
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.ImmediatSize = 8;
        XMMregXMMrm(pMyDisasm);
        if (!Security1(pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = SSE_REG+REG0;
        GV.EIP_++;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 37
 * ==================================================================== */
void __bea_callspec__ pcmpgtq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE42_INSTRUCTION+COMPARISON_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PCMPGTQ;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 3a 14
 * ==================================================================== */
void __bea_callspec__ pextrb_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+INSERTION_EXTRACTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PEXTRB;
        if ((*pMyDisasm).Archi == 64) {
            (*pMyDisasm).Instruction.OperandSize = 64;
        }
        GV.ImmediatSize = 8;
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        if (GV.MOD_!= 0x3) {
            (*pMyDisasm).Argument1.ArgSize = 8;
        }
        else {
            (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
        }
        RegSSE_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP;
        if (!Security1(pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.EIP_++;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 3a 16
 * ==================================================================== */
void __bea_callspec__ pextrd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Argument2.ArgSize = 128;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+INSERTION_EXTRACTION;
        GV.ImmediatSize = 8;
        if ((*pMyDisasm).Prefix.REX.W_) {
            (*pMyDisasm).Instruction.Mnemonic = I_PEXTRQ;
            (*pMyDisasm).Instruction.OperandSize = 64;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Argument1.ArgSize = 64;
        }
        else {
            (*pMyDisasm).Instruction.Mnemonic = I_PEXTRD;
            if ((*pMyDisasm).Archi == 64) {
                (*pMyDisasm).Instruction.OperandSize = 64;
            }
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            if (GV.MOD_!= 0x3) {
                (*pMyDisasm).Argument1.ArgSize = 32;
            }
            else {
                (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
            }
        }
        RegSSE_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP;
        if (!Security1(pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.EIP_++;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f c5
 * ==================================================================== */
void __bea_callspec__ pextrw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (*pMyDisasm).Instruction.Mnemonic = I_PEXTRW;
        if ((*pMyDisasm).Archi == 64) {
            (*pMyDisasm).Instruction.OperandSize = 64;
        }
        GV.ImmediatSize = 8;
        MOD_RM_SSE(&(*pMyDisasm).Argument2, pMyDisasm);
        (*pMyDisasm).Argument2.ArgSize = 128;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP;
        if (!Security1(pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.EIP_++;
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (*pMyDisasm).Instruction.Mnemonic = I_PEXTRW;
        if ((*pMyDisasm).Archi == 64) {
            (*pMyDisasm).Instruction.OperandSize = 64;
        }
        GV.ImmediatSize = 8;
        MOD_RM_MMX(&(*pMyDisasm).Argument2, pMyDisasm);
        (*pMyDisasm).Argument2.ArgSize = 64;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP;
        if (!Security1(pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.EIP_++;
    }
}

/* ====================================================================
 *      0x 0f 3a 15
 * ==================================================================== */
void __bea_callspec__ pextrw2_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+INSERTION_EXTRACTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PEXTRW;
        if ((*pMyDisasm).Archi == 64) {
            (*pMyDisasm).Instruction.OperandSize = 64;
        }
        GV.ImmediatSize = 8;
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        RegSSE_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
        if (GV.MOD_!= 0x3) {
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        else {
            (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
        }
        GV.EIP_ += GV.DECALAGE_EIP;
        if (!Security1(pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.EIP_++;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 02
 * ==================================================================== */
void __bea_callspec__ phaddd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PHADDD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PHADDD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        MMregMMrm(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 03
 * ==================================================================== */
void __bea_callspec__ phaddsw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PHADDSW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PHADDSW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        MMregMMrm(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 01
 * ==================================================================== */
void __bea_callspec__ phaddw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PHADDW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PHADDW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        MMregMMrm(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 41
 * ==================================================================== */
void __bea_callspec__ phminposuw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+HORIZONTAL_SEARCH;
        (*pMyDisasm).Instruction.Mnemonic = I_PHMINPOSUW;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 05
 * ==================================================================== */
void __bea_callspec__ phsubw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PHSUBW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PHSUBW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        MMregMMrm(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 06
 * ==================================================================== */
void __bea_callspec__ phsubd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PHSUBD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PHSUBD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        MMregMMrm(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 07
 * ==================================================================== */
void __bea_callspec__ phsubsw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PHSUBSW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PHSUBSW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        MMregMMrm(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 3a 20
 * ==================================================================== */
void __bea_callspec__ pinsrb_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+INSERTION_EXTRACTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PINSRB;
        GV.ImmediatSize = 8;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        RegSSE_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        if (GV.MOD_ != 3) {
            (*pMyDisasm).Argument2.ArgSize = 8;
        }
        GV.EIP_ += GV.DECALAGE_EIP;
        if (!Security1(pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.EIP_++;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 3a 22
 * ==================================================================== */
void __bea_callspec__ pinsrd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+INSERTION_EXTRACTION;
        if ((*pMyDisasm).Prefix.REX.W_) {
            (*pMyDisasm).Instruction.Mnemonic = I_PINSRQ;
            (*pMyDisasm).Instruction.OperandSize = 64;
            (*pMyDisasm).Argument2.ArgSize = 64;
        }
        else {
            (*pMyDisasm).Instruction.Mnemonic = I_PINSRD;
            (*pMyDisasm).Instruction.OperandSize = 32;
            (*pMyDisasm).Argument2.ArgSize = 32;
        }
        GV.ImmediatSize = 8;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        RegSSE_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP;
        if (!Security1(pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.EIP_++;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f c4
 * ==================================================================== */
void __bea_callspec__ pinsrw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (*pMyDisasm).Instruction.Mnemonic = I_PINSRW;
        (*pMyDisasm).Argument2.ArgSize = 16;
        GV.ImmediatSize = 8;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        RegSSE_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP;
        if (!Security1(pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.EIP_++;
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (*pMyDisasm).Instruction.Mnemonic = I_PINSRW;
        (*pMyDisasm).Argument2.ArgSize = 16;
        GV.ImmediatSize = 8;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        RegMMX_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP;
        if (!Security1(pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.EIP_++;
    }
}


/* ====================================================================
 *      0x 0f 38 3c
 * ==================================================================== */
void __bea_callspec__ pmaxsb_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_MINMAX;
        (*pMyDisasm).Instruction.Mnemonic = I_PMAXSB;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 3d
 * ==================================================================== */
void __bea_callspec__ pmaxsd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_MINMAX;
        (*pMyDisasm).Instruction.Mnemonic = I_PMAXSD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 3e
 * ==================================================================== */
void __bea_callspec__ pmaxuw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_MINMAX;
        (*pMyDisasm).Instruction.Mnemonic = I_PMAXUW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 3f
 * ==================================================================== */
void __bea_callspec__ pmaxud_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_MINMAX;
        (*pMyDisasm).Instruction.Mnemonic = I_PMAXUD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 38
 * ==================================================================== */
void __bea_callspec__ pminsb_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_MINMAX;
        (*pMyDisasm).Instruction.Mnemonic = I_PMINSB;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 39
 * ==================================================================== */
void __bea_callspec__ pminsd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_MINMAX;
        (*pMyDisasm).Instruction.Mnemonic = I_PMINSD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 3a
 * ==================================================================== */
void __bea_callspec__ pminuw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_MINMAX;
        (*pMyDisasm).Instruction.Mnemonic = I_PMINUW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 3b
 * ==================================================================== */
void __bea_callspec__ pminud_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_MINMAX;
        (*pMyDisasm).Instruction.Mnemonic = I_PMINUD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f da
 * ==================================================================== */
void __bea_callspec__ pminub_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (*pMyDisasm).Instruction.Mnemonic = I_PMINUB;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (*pMyDisasm).Instruction.Mnemonic = I_PMINUB;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        MMregMMrm(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f de
 * ==================================================================== */
void __bea_callspec__ pmaxub_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (*pMyDisasm).Instruction.Mnemonic = I_PMAXUB;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (*pMyDisasm).Instruction.Mnemonic = I_PMAXUB;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        MMregMMrm(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f ea
 * ==================================================================== */
void __bea_callspec__ pminsw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (*pMyDisasm).Instruction.Mnemonic = I_PMINSW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (*pMyDisasm).Instruction.Mnemonic = I_PMINSW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        MMregMMrm(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f ee
 * ==================================================================== */
void __bea_callspec__ pmaxsw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (*pMyDisasm).Instruction.Mnemonic = I_PMAXSW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (*pMyDisasm).Instruction.Mnemonic = I_PMAXSW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        MMregMMrm(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 04
 * ==================================================================== */
void __bea_callspec__ pmaddubsw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PMADDUBSW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PMADDUBSW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        MMregMMrm(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f d7
 * ==================================================================== */
void __bea_callspec__ pmovmskb_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (*pMyDisasm).Instruction.Mnemonic = I_PMOVMSKB;
        if ((*pMyDisasm).Archi == 64) {
            (*pMyDisasm).Instruction.OperandSize = 64;
        }
        (*pMyDisasm).Argument2.ArgSize = 128;
        MOD_RM_SSE(&(*pMyDisasm).Argument2, pMyDisasm);
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP;
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (*pMyDisasm).Instruction.Mnemonic = I_PMOVMSKB;
        if ((*pMyDisasm).Archi == 64) {
            (*pMyDisasm).Instruction.OperandSize = 64;
        }
        (*pMyDisasm).Argument2.ArgSize = 64;
        MOD_RM_MMX(&(*pMyDisasm).Argument2, pMyDisasm);
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP;
    }
}


/* ====================================================================
 *      0x 0f 38 21
 * ==================================================================== */
void __bea_callspec__ pmovsxbd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PMOVSXBD;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 22
 * ==================================================================== */
void __bea_callspec__ pmovsxbq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PMOVSXBQ;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 20
 * ==================================================================== */
void __bea_callspec__ pmovsxbw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PMOVSXBW;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 25
 * ==================================================================== */
void __bea_callspec__ pmovsxdq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PMOVSXDQ;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 23
 * ==================================================================== */
void __bea_callspec__ pmovsxwd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PMOVSXWD;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 24
 * ==================================================================== */
void __bea_callspec__ pmovsxwq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PMOVSXWQ;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 31
 * ==================================================================== */
void __bea_callspec__ pmovzxbd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PMOVZXBD;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 32
 * ==================================================================== */
void __bea_callspec__ pmovzxbq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PMOVZXBQ;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 30
 * ==================================================================== */
void __bea_callspec__ pmovzxbw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PMOVZXBW;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 35
 * ==================================================================== */
void __bea_callspec__ pmovzxdq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PMOVZXDQ;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 33
 * ==================================================================== */
void __bea_callspec__ pmovzxwd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PMOVZXWD;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 34
 * ==================================================================== */
void __bea_callspec__ pmovzxwq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PMOVZXWQ;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 28
 * ==================================================================== */
void __bea_callspec__ pmuldq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PMULDQ;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 40
 * ==================================================================== */
void __bea_callspec__ pmulld_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PMULLD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 0b
 * ==================================================================== */
void __bea_callspec__ pmulhrsw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PMULHRSW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_PMULHRSW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        MMregMMrm(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f e4
 * ==================================================================== */
void __bea_callspec__ pmulhuw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Mnemonic = I_PMULHUW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Mnemonic = I_PMULHUW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        MMregMMrm(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f f4
 * ==================================================================== */
void __bea_callspec__ pmuludq_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Mnemonic = I_PMULUDQ;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Mnemonic = I_PMULUDQ;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        MMregMMrm(pMyDisasm);
    }
}


/* =======================================
 *      0x 0f b8
 * ======================================= */
void __bea_callspec__ popcnt_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE42_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_POPCNT;
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_POPCNT);
}


/* ====================================================================
 *      0x 0f f6
 * ==================================================================== */
void __bea_callspec__ psadbw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Mnemonic = I_PSADBW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Mnemonic = I_PSADBW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        MMregMMrm(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 00
 * ==================================================================== */
void __bea_callspec__ pshufb_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+SHUFFLE_UNPACK;
        (*pMyDisasm).Instruction.Mnemonic = I_PSHUFB;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+SHUFFLE_UNPACK;
        (*pMyDisasm).Instruction.Mnemonic = I_PSHUFB;
        MMregMMrm(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 70
 * ==================================================================== */
void __bea_callspec__ pshufw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SIMD128bits;
    /* ========= 0xf3 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Mnemonic = I_PSHUFHW;
        GV.ImmediatSize = 8;
        XMMregXMMrm(pMyDisasm);
        if (!Security1(pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.EIP_++;
    }
    /* ========= 0xf2 */
    else if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Mnemonic = I_PSHUFLW;
        XMMregXMMrm(pMyDisasm);
        if (!Security1(pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.EIP_++;
    }

    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Mnemonic = I_PSHUFD;
        GV.ImmediatSize = 8;
        XMMregXMMrm(pMyDisasm);
        if (!Security1(pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.EIP_++;
    }
    else {
        (*pMyDisasm).Instruction.Mnemonic = I_PSHUFW;
        GV.ImmediatSize = 8;
        MMregMMrm(pMyDisasm);
        if (!Security1(pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.EIP_++;
    }
}

/* ====================================================================
 *      0x 0f 38 08
 * ==================================================================== */
void __bea_callspec__ psignb_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+PACKED_SIGN;
        (*pMyDisasm).Instruction.Mnemonic = I_PSIGNB;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+PACKED_SIGN;
        (*pMyDisasm).Instruction.Mnemonic = I_PSIGNB;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        MMregMMrm(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 0a
 * ==================================================================== */
void __bea_callspec__ psignd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+PACKED_SIGN;
        (*pMyDisasm).Instruction.Mnemonic = I_PSIGND;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+PACKED_SIGN;
        (*pMyDisasm).Instruction.Mnemonic = I_PSIGND;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        MMregMMrm(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 09
 * ==================================================================== */
void __bea_callspec__ psignw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+PACKED_SIGN;
        (*pMyDisasm).Instruction.Mnemonic = I_PSIGNW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+PACKED_SIGN;
        (*pMyDisasm).Instruction.Mnemonic = I_PSIGNW;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        MMregMMrm(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f fb
 * ==================================================================== */
void __bea_callspec__ psubq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SIMD128bits;
        (*pMyDisasm).Instruction.Mnemonic = I_PSUBQ;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SIMD128bits;
        (*pMyDisasm).Instruction.Mnemonic = I_PSUBQ;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        MMregMMrm(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 17
 * ==================================================================== */
void __bea_callspec__ ptest_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_TEST;
        (*pMyDisasm).Instruction.Mnemonic = I_PTEST;
        (*pMyDisasm).Argument1.AccessMode = READ;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }

}

/* ====================================================================
 *      0x 0f 6c
 * ==================================================================== */
void __bea_callspec__ punpcklqdq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SIMD128bits;
        (*pMyDisasm).Instruction.Mnemonic = I_PUNPCKLQDQ;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 6d
 * ==================================================================== */
void __bea_callspec__ punpckhqdq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SIMD128bits;
        (*pMyDisasm).Instruction.Mnemonic = I_PUNPCKHQDQ;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 53
 * ==================================================================== */
void __bea_callspec__ rcpps_(PDISASM pMyDisasm)
{
    /* ========== 0xf3 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_RCPSS;
        XMMregXMMrm32(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_RCPPS;
        XMMregXMMrm(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 3a 09
 * ==================================================================== */
void __bea_callspec__ roundpd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+ROUND_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_ROUNDPD;
        GV.ImmediatSize = 8;
        XMMregXMMrm(pMyDisasm);
        if (!Security1(pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.EIP_++;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 3a 08
 * ==================================================================== */
void __bea_callspec__ roundps_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+ROUND_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_ROUNDPS;
        GV.ImmediatSize = 8;
        XMMregXMMrm(pMyDisasm);
        if (!Security1(pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.EIP_++;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 3a 0b
 * ==================================================================== */
void __bea_callspec__ roundsd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+ROUND_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_ROUNDSD;
        GV.ImmediatSize = 8;
        XMMregXMMrm(pMyDisasm);
        if (!Security1(pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.EIP_++;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 3a 0a
 * ==================================================================== */
void __bea_callspec__ roundss_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+ROUND_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_ROUNDSS;
        GV.ImmediatSize = 8;
        XMMregXMMrm32(pMyDisasm);
        if (!Security1(pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.EIP_++;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 52
 * ==================================================================== */
void __bea_callspec__ rsqrtps_(PDISASM pMyDisasm)
{
    /* ========== 0xf3 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_RSQRTSS;
        XMMregXMMrm32(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_RSQRTPS;
        XMMregXMMrm(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f c6
 * ==================================================================== */
void __bea_callspec__ shufps_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    GV.ImmediatSize = 8;
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SHUFFLE_UNPACK;
        (*pMyDisasm).Instruction.Mnemonic = I_SHUFPD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SHUFFLE_UNPACK;
        (*pMyDisasm).Instruction.Mnemonic = I_SHUFPS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    (*pMyDisasm).Argument1.AccessMode = READ;
    if (!Security1(pMyDisasm)) return;
    (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
    (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument3.ArgSize = 8;
    GV.EIP_++;
}


/* ====================================================================
 *      0x 0f 51
 * ==================================================================== */
void __bea_callspec__ sqrtps_VW(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_SQRTSD;
        XMMregXMMrm64(pMyDisasm);
    }
    /* ========= 0xf3 */
    else if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_SQRTSS;
        XMMregXMMrm32(pMyDisasm);
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_SQRTPD;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_SQRTPS;
        XMMregXMMrm(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 5c
 * ==================================================================== */
void __bea_callspec__ subps_VW(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepne) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_SUBSD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm64(pMyDisasm);
    }
    /* ========= 0xf3 */
    else if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.RepeatState = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_SUBSS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm32(pMyDisasm);
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_SUBPD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_SUBPS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 2e
 * ==================================================================== */
void __bea_callspec__ ucomiss_VW(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Instruction.OperandSize == 16) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+COMPARISON_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_UCOMISD;
        (*pMyDisasm).Argument1.AccessMode = READ;
        XMMregXMMrm32(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+COMPARISON_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_UCOMISS;
        (*pMyDisasm).Argument1.AccessMode = READ;
        XMMregXMMrm(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 15
 * ==================================================================== */
void __bea_callspec__ unpckhps_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Instruction.OperandSize == 16) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SHUFFLE_UNPACK;
        (*pMyDisasm).Instruction.Mnemonic = I_UNPCKHPD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SHUFFLE_UNPACK;
        (*pMyDisasm).Instruction.Mnemonic = I_UNPCKHPS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 14
 * ==================================================================== */
void __bea_callspec__ unpcklps_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SHUFFLE_UNPACK;
        (*pMyDisasm).Instruction.Mnemonic = I_UNPCKLPD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SHUFFLE_UNPACK;
        (*pMyDisasm).Instruction.Mnemonic = I_UNPCKLPS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 57
 * ==================================================================== */
void __bea_callspec__ xorps_VW(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSizeState == InUsePrefix) {
        PrefOpSizeMandatory(pMyDisasm);
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+LOGICAL_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_XORPD;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+LOGICAL_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_XORPS;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        XMMregXMMrm(pMyDisasm);
    }
}
