#pragma once

#include <ultra64.h>

#include "types.h"
#include "level_table.h"

#include "game/emutest.h"
#include "game/level_update.h"
#include "game/main.h"



enum CauseDescriptions {
    CAUSE_DESC_INT     = (EXC_INT     >> CAUSE_EXCSHIFT),
    CAUSE_DESC_MOD     = (EXC_MOD     >> CAUSE_EXCSHIFT),
    CAUSE_DESC_RMISS   = (EXC_RMISS   >> CAUSE_EXCSHIFT),
    CAUSE_DESC_WMISS   = (EXC_WMISS   >> CAUSE_EXCSHIFT),
    CAUSE_DESC_RADE    = (EXC_RADE    >> CAUSE_EXCSHIFT),
    CAUSE_DESC_WADE    = (EXC_WADE    >> CAUSE_EXCSHIFT),
    CAUSE_DESC_IBE     = (EXC_IBE     >> CAUSE_EXCSHIFT),
    CAUSE_DESC_DBE     = (EXC_DBE     >> CAUSE_EXCSHIFT),
    CAUSE_DESC_SYSCALL = (EXC_SYSCALL >> CAUSE_EXCSHIFT),
    CAUSE_DESC_BREAK   = (EXC_BREAK   >> CAUSE_EXCSHIFT),
    CAUSE_DESC_II      = (EXC_II      >> CAUSE_EXCSHIFT),
    CAUSE_DESC_CPU     = (EXC_CPU     >> CAUSE_EXCSHIFT),
    CAUSE_DESC_OV      = (EXC_OV      >> CAUSE_EXCSHIFT),
    CAUSE_DESC_TRAP    = (EXC_TRAP    >> CAUSE_EXCSHIFT),
    CAUSE_DESC_VCEI    = (EXC_VCEI    >> CAUSE_EXCSHIFT),
    CAUSE_DESC_FPE     = (EXC_FPE     >> CAUSE_EXCSHIFT),
    CAUSE_DESC_WATCH   = 16, // (EXC_WATCH   >> CAUSE_EXCSHIFT),
    CAUSE_DESC_VCED    = 17, // (EXC_VCED    >> CAUSE_EXCSHIFT),
    NUM_CAUSE_DESC,
};

#define FPCSR_SHIFT 17
#define FPCSR_CAUSES (6 - 1)
#define FPCSR_SHIFT_2 (FPCSR_SHIFT - FPCSR_CAUSES)

enum FPCSRDescriptions {
    FPCSR_DESC_CE = (FPCSR_CAUSES - CTZ(FPCSR_CE >> FPCSR_SHIFT_2)), // Unimplemented operation.
    FPCSR_DESC_CV = (FPCSR_CAUSES - CTZ(FPCSR_CV >> FPCSR_SHIFT_2)), // Invalid operation.
    FPCSR_DESC_CZ = (FPCSR_CAUSES - CTZ(FPCSR_CZ >> FPCSR_SHIFT_2)), // Division by zero.
    FPCSR_DESC_CO = (FPCSR_CAUSES - CTZ(FPCSR_CO >> FPCSR_SHIFT_2)), // Overflow.
    FPCSR_DESC_CU = (FPCSR_CAUSES - CTZ(FPCSR_CU >> FPCSR_SHIFT_2)), // Underflow.
    FPCSR_DESC_CI = (FPCSR_CAUSES - CTZ(FPCSR_CI >> FPCSR_SHIFT_2)), // Inexact operation.
    NUM_FPCSR_DESC,
};


extern char HackerSM64_version_txt[];
extern char CrashScreen_version_txt[];


const char* str_null_fallback(const char* str, const char* fallback);

const char* get_thread_name(OSThread* thread);
const char* get_thread_state_str(OSThread* thread);
const char* get_thread_flags_str(OSThread* thread);

const char* get_warp_node_name(enum WarpNodes id);
const char* get_level_name(enum LevelNum levelNum);

const char* get_segment_name(u8 segmentId);
const char* get_segment_sub_name(u8 segmentId);
const char* get_hardcoded_memory_str(Address addr);

const char* get_processor_name(u8 imp);

const char* get_cause_desc_simple(u32 cause);
const char* get_cause_desc(__OSThreadContext* tc, _Bool specific);
const char* get_fpcsr_desc(u32 fpcsr, _Bool specific);

const char* get_emulator_name(enum Emulator emu);

const char* get_map_symbol_type_desc(char c);
