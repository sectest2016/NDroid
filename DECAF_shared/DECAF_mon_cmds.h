/**
 * Copyright (C) <2012> <Syracuse System Security (Sycure) Lab>
 *
 * This program is free software; you can redistribute it and/or 
 * modify it under the terms of the GNU General Public License as 
 * published by the Free Software Foundation; either version 2 of 
 * the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public 
 * License along with this program; if not, write to the Free 
 * Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, 
 * MA 02111-1307 USA
**/

{
  .name       = "load_plugin",
  .args_type  = _QEMU_MON_KEY_VALUE("filename","F"),
  .params     = "filename",
  .help       = "Load a DECAF plugin",
  ._QEMU_MON_HANDLER_CMD_NEW = DECAF_do_load_plugin_internal,
},

{
  .name       = "unload_plugin",
  .args_type  = "",
  .params     = "",
  .help       = "Unload the current DECAF plugin",
  ._QEMU_MON_HANDLER_CMD_NEW = do_unload_plugin,
},


/* operating system information */
{
  .name		= "guest_ps|ps",
  .args_type	= "",
  ._QEMU_MON_HANDLER_INFO = do_guest_ps,
  .params		= "", 
  .help		= "list the processes on guest system"
},

{  .name        = "guest_pt|pt",
   .args_type   = "",
   ._QEMU_MON_HANDLER_INFO = do_guest_pt,
   .params      = "",
   .help        = "Prints the process list including threads"
},

{
  .name		= "guest_modules|pm", 
  .args_type	= _QEMU_MON_KEY_VALUE("pid","i"),
  ._QEMU_MON_HANDLER_CMD	= do_guest_modules,
  .params		= "pid",
  .help		= "list the modules of the process with <pid>"
},

{
  .name         = "get_symbol_addr",
  .args_type    = _QEMU_MON_KEY_VALUE("pid","i") _QEMU_MON_KEY_VALUE("modname","s") _QEMU_MON_KEY_VALUE("symname", "s"),
  ._QEMU_MON_HANDLER_CMD = do_sym_to_addr,
  .params       = "pid moduleName symbolName",
  .help         = "Tries to retrieve the address of a symbol in a module"
},

/* NDROID START */
/* NDroid commands */
{
  .name         = "nd_trace_pid",
  .args_type    = _QEMU_MON_KEY_VALUE("pid","i"),
  ._QEMU_MON_HANDLER_CMD = nd_trace_pid,
  .params       = "pid",
  .help         = "NDroid: trace a running process with pid = <pid>"
},

{
  .name         = "nd_trace_uid",
  .args_type    = _QEMU_MON_KEY_VALUE("uid","i"),
  ._QEMU_MON_HANDLER_CMD = nd_trace_uid,
  .params       = "uid",
  .help         = "NDroid: trace a running process with uid = <uid>"
},

{
  .name         = "nd_wait_and_trace_uid",
  .args_type    = _QEMU_MON_KEY_VALUE("uid","i") _QEMU_MON_KEY_VALUE("libStartAddr", "s") _QEMU_MON_KEY_VALUE("libEndAddr", "s"),
  ._QEMU_MON_HANDLER_CMD = nd_wait_and_trace_uid,
  .params       = "uid libStartAddr libEndAddr",
  .help         = "NDroid: wait a process with uid = <uid> to start and trace it"
},

{
  .name         = "nd_stop_trace_pid",
  .args_type    = _QEMU_MON_KEY_VALUE("pid","i"),
  ._QEMU_MON_HANDLER_CMD = nd_stop_trace_pid,
  .params       = "pid",
  .help         = "NDroid: stop tracing the process with pid = <pid>"
},

{
  .name         = "nd_stop_trace_uid",
  .args_type    = _QEMU_MON_KEY_VALUE("uid","i"),
  ._QEMU_MON_HANDLER_CMD = nd_stop_trace_uid,
  .params       = "uid",
  .help         = "NDroid: stop tracing the process with uid = <uid>"
},
/* NDROID END */
