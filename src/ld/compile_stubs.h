// SPDX-License-Identifier: APSL-2.0

#pragma once

static const char compile_stubs[] = {
#embed "../../compile_stubs" suffix(, '\0') if_empty('\0')
};
