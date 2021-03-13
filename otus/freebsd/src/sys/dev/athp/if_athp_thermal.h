/*
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
#ifndef	__IF_ATHP_THERMAL_H__
#define	__IF_ATHP_THERMAL_H__

struct ath10k;

#define ATH10K_QUIET_PERIOD_DEFAULT     100
#define ATH10K_QUIET_PERIOD_MIN         25
#define ATH10K_QUIET_START_OFFSET       10
#define ATH10K_HWMON_NAME_LEN           15
#define ATH10K_THERMAL_SYNC_TIMEOUT_HZ (5*HZ)
#define ATH10K_THERMAL_THROTTLE_MAX     100

struct ath10k_thermal {
#if 0
	struct thermal_cooling_device *cdev;
#endif
	struct ath10k_compl wmi_sync;

	/* protected by conf_mutex */
	u32 throttle_state;
	u32 quiet_period;
	/* temperature value in Celcius degree
	 * protected by data_lock
	 */
	int temperature;
};

int ath10k_thermal_register(struct ath10k *ar);
void ath10k_thermal_unregister(struct ath10k *ar);
void ath10k_thermal_event_temperature(struct ath10k *ar, int temperature);
void ath10k_thermal_set_throttling(struct ath10k *ar);

#endif	/* __IF_ATHP_THERMAL_H__ */