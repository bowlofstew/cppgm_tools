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
 *      0f00h
 * ==================================================================== */
void __bea_callspec__ G6_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_))) >> 3) & 0x7;

    if (GV.REGOPCODE == 0) {
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        if (GV.MOD_!= 0x3) {
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        (*pMyDisasm).Instruction.Mnemonic = I_SLDT;
        (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+MEMORY_MANAGEMENT_REG+REG1;
        (*pMyDisasm).Argument2.ArgSize = 32;
        GV.EIP_+= GV.DECALAGE_EIP;
    }
    else if (GV.REGOPCODE == 1) {
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        if (GV.MOD_!= 0x3) {
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        (*pMyDisasm).Instruction.Mnemonic = I_STR;
        (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+MEMORY_MANAGEMENT_REG+REG3;
        (*pMyDisasm).Argument2.ArgSize = 16;
        GV.EIP_+= GV.DECALAGE_EIP;
    }
    else if (GV.REGOPCODE == 2) {
        (*pMyDisasm).Instruction.OperandSize = 16;
        (*pMyDisasm).Argument2.ArgSize = 16;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        (*pMyDisasm).Instruction.Mnemonic = I_LLDT;
        (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+MEMORY_MANAGEMENT_REG+REG1;
        (*pMyDisasm).Argument1.ArgSize = 16;
        GV.EIP_+= GV.DECALAGE_EIP;
    }
    else if (GV.REGOPCODE == 3) {
        (*pMyDisasm).Instruction.OperandSize = 16;
        (*pMyDisasm).Argument2.ArgSize = 16;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        (*pMyDisasm).Instruction.Mnemonic = I_LTR;
        (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+MEMORY_MANAGEMENT_REG+REG3;
        (*pMyDisasm).Argument1.ArgSize = 16;
        GV.EIP_+= GV.DECALAGE_EIP;
    }
    else if (GV.REGOPCODE == 4) {
        (*pMyDisasm).Instruction.OperandSize = 16;
        (*pMyDisasm).Argument1.ArgSize = 16;
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        (*pMyDisasm).Instruction.Mnemonic = I_VERR;
        GV.EIP_+= GV.DECALAGE_EIP;
    }
    else if (GV.REGOPCODE == 5) {
        (*pMyDisasm).Instruction.OperandSize = 16;
        (*pMyDisasm).Argument1.ArgSize = 16;
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        (*pMyDisasm).Instruction.Mnemonic = I_VERW;
        GV.EIP_+= GV.DECALAGE_EIP;
    }
    else if (GV.REGOPCODE == 6) {
        FailDecode(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}

