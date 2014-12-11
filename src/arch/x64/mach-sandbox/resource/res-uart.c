/*
 * resource/res-uart.c
 *
 * Copyright(c) 2007-2014 Jianjun Jiang <8192542@qq.com>
 * Official site: http://xboot.org
 * Mobile phone: +86-18665388956
 * QQ: 8192542
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#include <xboot.h>

static struct resource_t res_uart = {
	.name		= "sandbox-uart",
	.id			= 0,
};

static __init void resource_uart_init(void)
{
	if(register_resource(&res_uart))
		LOG("Register resource %s:'%s.%d'", res_uart.mach, res_uart.name, res_uart.id);
	else
		LOG("Failed to register resource %s:'%s.%d'", res_uart.mach, res_uart.name, res_uart.id);
}

static __exit void resource_uart_exit(void)
{
	if(unregister_resource(&res_uart))
		LOG("Unregister resource %s:'%s.%d'", res_uart.mach, res_uart.name, res_uart.id);
	else
		LOG("Failed to unregister resource %s:'%s.%d'", res_uart.mach, res_uart.name, res_uart.id);
}

resource_initcall(resource_uart_init);
resource_exitcall(resource_uart_exit);