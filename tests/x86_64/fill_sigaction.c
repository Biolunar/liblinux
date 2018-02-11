/*
 * Copyright 2018 Mahdi Khanalizadeh
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "../fill_sigaction.h"
#include "../memset.h"

#include <liblinux_syscall/syscall.h>

void fill_sigaction(struct linux_sigaction_t* sa, linux_sighandler_t handler)
{
	memset(sa, 0, sizeof *sa);
	sa->sa_handler = handler;
	sa->sa_flags = linux_SA_RESTORER;
	sa->sa_restorer = &linux_rt_sigreturn;
}
