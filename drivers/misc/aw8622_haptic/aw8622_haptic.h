#ifndef _AW8622_HAPTIC_H_
#define _AW8622_HAPTIC_H_

#include <linux/hrtimer.h>
#include <linux/mutex.h>
#include <linux/workqueue.h>
#include <linux/pinctrl/consumer.h>

#define AW_GPIO_MODE_LED_DEFAULT                (0)
#define HAPTIC_GPIO_AW8622_DEFAULT              (0)
#define HAPTIC_GPIO_AW8622_SET                  (1)
#define HAPTIC_PWM_MEMORY_MODE_CLOCK            (26000000)
#define HAPTIC_PWM_OLD_MODE_CLOCK               (26000000)

#define DEFAULT_FREQUENCY                       (208)
#define MIN_FREQUENCY                           (203)
#define MAX_FREQUENCY                           (212)

struct aw8622_haptic {
	struct device *dev;
	struct hrtimer timer;
	struct work_struct play_work;
	struct work_struct stop_play_work;
	struct delayed_work hw_off_work;
	struct workqueue_struct *aw8622_wq;
	struct mutex mutex_lock;
	struct pinctrl *ppinctrl_pwm;

	int hwen_gpio;
	unsigned int pwm_ch;
	unsigned int duration;
	unsigned int frequency;
	unsigned int center_freq;
	unsigned int default_pwm_freq;
	unsigned int wave_sample_period;

	bool is_power_on;
	bool is_actived;
	bool is_hwen;
};

#endif /* _AW8622_HAPTIC_H_ */
