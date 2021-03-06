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
 *      0f6h
 * ==================================================================== */
void __bea_callspec__ G3_Eb(PDISASM pMyDisasm)
{
    GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_))) >> 3) & 0x7;
    if (GV.REGOPCODE == 0) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
        (*pMyDisasm).Instruction.Mnemonic = I_TEST;
        EbIb(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ;
        FillFlags(pMyDisasm, EFLAGS_TEST);
    }
    else if (GV.REGOPCODE == 1) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
        (*pMyDisasm).Instruction.Mnemonic = I_TEST;
        EbIb(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ;
        FillFlags(pMyDisasm, EFLAGS_TEST);
    }
    else if (GV.REGOPCODE == 2) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_NOT;
        Eb(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        FillFlags(pMyDisasm, EFLAGS_NOT);
        if ((*pMyDisasm).Prefix.LockState == InvalidPrefix && (*pMyDisasm).Argument1.ArgType & MEMORY_TYPE) {
            (*pMyDisasm).Prefix.LockState = InUsePrefix;
        }
    }
    else if (GV.REGOPCODE == 3) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_NEG;
        Eb(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        FillFlags(pMyDisasm, EFLAGS_NEG);
        if ((*pMyDisasm).Prefix.LockState == InvalidPrefix && (*pMyDisasm).Argument1.ArgType & MEMORY_TYPE) {
            (*pMyDisasm).Prefix.LockState = InUsePrefix;
        }
    }
    else if (GV.REGOPCODE == 4) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_MUL;
        Eb(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument2.ArgSize = 8;
        (*pMyDisasm).Argument2.AccessMode = READ+WRITE;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG0;
        FillFlags(pMyDisasm, EFLAGS_MUL);
    }
    else if (GV.REGOPCODE == 5) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_IMUL;
        Eb(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument2.ArgSize = 8;
        (*pMyDisasm).Argument2.AccessMode = READ+WRITE;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG0;
        FillFlags(pMyDisasm, EFLAGS_IMUL);
    }
    else if (GV.REGOPCODE == 6) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_DIV;
        Eb(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument2.ArgSize = 8;
        (*pMyDisasm).Argument2.AccessMode = READ+WRITE;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG0;
        FillFlags(pMyDisasm, EFLAGS_DIV);
    }
    else if (GV.REGOPCODE == 7) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_IDIV;
        Eb(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument2.ArgSize = 8;
        (*pMyDisasm).Argument2.AccessMode = READ+WRITE;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG0;
        FillFlags(pMyDisasm, EFLAGS_IDIV);
    }
}

/* ====================================================================
 *      0f7h
 * ==================================================================== */
void __bea_callspec__ G3_Ev(PDISASM pMyDisasm)
{
    GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_))) >> 3) & 0x7;
    if (GV.REGOPCODE == 0) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
        (*pMyDisasm).Instruction.Mnemonic = I_TEST;
        EvIv(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ;
        FillFlags(pMyDisasm, EFLAGS_TEST);
    }
    else if (GV.REGOPCODE == 1) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
        (*pMyDisasm).Instruction.Mnemonic = I_TEST;
        EvIv(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ;
        FillFlags(pMyDisasm, EFLAGS_TEST);
    }
    else if (GV.REGOPCODE == 2) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_NOT;
        Ev(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        FillFlags(pMyDisasm, EFLAGS_NOT);
        if ((*pMyDisasm).Prefix.LockState == InvalidPrefix && (*pMyDisasm).Argument1.ArgType & MEMORY_TYPE) {
            (*pMyDisasm).Prefix.LockState = InUsePrefix;
        }
    }
    else if (GV.REGOPCODE == 3) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_NEG;
        Ev(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        FillFlags(pMyDisasm, EFLAGS_NEG);
        if ((*pMyDisasm).Prefix.LockState == InvalidPrefix && (*pMyDisasm).Argument1.ArgType & MEMORY_TYPE) {
            (*pMyDisasm).Prefix.LockState = InUsePrefix;
        }
    }
    else if (GV.REGOPCODE == 4) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_MUL;
        (*pMyDisasm).Argument2.ArgSize = (*pMyDisasm).Instruction.OperandSize;
        Ev(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument2.AccessMode = READ+WRITE;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG0+REG2;
        FillFlags(pMyDisasm, EFLAGS_MUL);
    }
    else if (GV.REGOPCODE == 5) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_IMUL;
        (*pMyDisasm).Argument2.ArgSize = (*pMyDisasm).Instruction.OperandSize;
        Ev(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument2.AccessMode = READ+WRITE;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG0+REG2;
        FillFlags(pMyDisasm, EFLAGS_IMUL);
    }
    else if (GV.REGOPCODE == 6) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_DIV;
        (*pMyDisasm).Argument2.ArgSize = (*pMyDisasm).Instruction.OperandSize;
        (*pMyDisasm).Argument3.ArgSize = (*pMyDisasm).Instruction.OperandSize;
        Ev(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument2.AccessMode = READ+WRITE;
        (*pMyDisasm).Argument3.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG2;
        (*pMyDisasm).Argument3.AccessMode = READ+WRITE;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG0+REG2;
        FillFlags(pMyDisasm, EFLAGS_DIV);
    }
    else if (GV.REGOPCODE == 7) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_IDIV;
        (*pMyDisasm).Argument2.ArgSize = (*pMyDisasm).Instruction.OperandSize;
        (*pMyDisasm).Argument3.ArgSize = (*pMyDisasm).Instruction.OperandSize;
        Ev(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument2.AccessMode = READ+WRITE;
        (*pMyDisasm).Argument3.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG2;
        (*pMyDisasm).Argument3.AccessMode = READ+WRITE;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG0+REG2;
        FillFlags(pMyDisasm, EFLAGS_IDIV);
    }
}
