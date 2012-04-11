<?php // $Id$

/**
 * @file
 * 
 * Allow configuration changes for alerts.
 */

/**
 * Form builder for the user alerts settings form.
 *
 * @ingroup forms
 */

function user_alert_admin_settings() {		
	$form = array();

	$form['user_alert_label'] = array(
		'#title' => 'User alert label',
		'#type' => 'textfield',
		'#description' => t('The label next to every user alert message.'),
		'#default_value' =>	variable_get('user_alert_label', 'User Alert'),
	);
	
	return system_settings_form($form);	
}