
px4_add_board(
	PLATFORM posix
	VENDOR px4
	MODEL sitl
	LABEL default
	TESTING

	DRIVERS
		#barometer # all available barometer drivers
		batt_smbus
		camera_trigger
		differential_pressure # all available differential pressure drivers
		distance_sensor # all available distance sensor drivers
		gps
		#imu # all available imu drivers
		#magnetometer # all available magnetometer drivers
		pwm_out_sim
		#telemetry # all available telemetry drivers
		tone_alarm_sim
		#uavcan

	MODULES
		attitude_estimator_q
		camera_feedback
		commander
		dataman
		ekf2
		events
		fw_att_control
		fw_pos_control_l1
		gnd_att_control
		gnd_pos_control
		land_detector
		landing_target_estimator
		load_mon
		local_position_estimator
		logger
		mavlink
		mc_att_control
		mc_pos_control
		navigator
		position_estimator_inav
		replay
		sense_avoid
		sensors
		simulator
		vmount
		vtol_att_control
		wind_estimator

	SYSTEMCMDS
		#bl_update
		#config
		#dumpfile
		dyn
		esc_calib
		#hardfault_log
		led_control
		mixer
		motor_ramp
		#mtd
		#nshterm
		param
		perf
		pwm
		reboot
		sd_bench
		shutdown
		tests # tests and test runner
		top
		topic_listener
		tune_control
		ver

	EXAMPLES
		bottle_drop # OBC challenge
		dyn_hello # dynamically loading modules example
		fixedwing_control # Tutorial code from https://px4.io/dev/example_fixedwing_control
		hello
		#hwtest # Hardware test
		px4_mavlink_debug # Tutorial code from https://px4.io/dev/debug_values
		px4_simple_app # Tutorial code from https://px4.io/dev/px4_simple_app
		rover_steering_control # Rover example app
		segway
	)

set(config_sitl_viewer jmavsim CACHE STRING "viewer for sitl")
set_property(CACHE config_sitl_viewer PROPERTY STRINGS "jmavsim;none")

set(config_sitl_debugger disable CACHE STRING "debugger for sitl")
set_property(CACHE config_sitl_debugger PROPERTY STRINGS "disable;gdb;lldb")

# If the environment variable 'replay' is defined, we are building with replay
# support. In this case, we enable the orb publisher rules.
set(REPLAY_FILE "$ENV{replay}")
if(REPLAY_FILE)
	message("Building with uorb publisher rules support")
	add_definitions(-DORB_USE_PUBLISHER_RULES)
endif()

set(ENABLE_LOCKSTEP_SCHEDULER yes)
