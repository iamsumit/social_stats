<?php

/**
 * @file
 * Administrative page callbacks for Service Links module.
 */

/**
 * Configuration form for the general settings for Social Stats module.
 */
function social_stats_general_settings_form() {
  // Add the javascript.
  $path = drupal_get_path('module', 'social_stats');
  drupal_add_js($path .'/js/social_stats.js');
  $form['basic_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Basic Settings'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#tree' => FALSE,
    '#weight' => -1,
  );

  $form['basic_settings']['social_stats_options'] = array(
    '#type' => 'radios',
    '#title' => t('Select options'),
    '#options' => array('Start Date', 'Offset'),
    '#attributes' => array('class' => 'date-options'),
    '#default_value' => variable_get('social_stats_options', 0),
  );

  $form['basic_settings']['social_stats_start_date'] = array(
    '#title' => t('Start Date (DD/MM/YYYY)'),
    '#type' => 'textfield',
    '#maxlength' => 20,
    '#attributes' => array('class' => 'date-start'),
    '#default_value' => variable_get('social_stats_start_date', '01/01/1970'),
    '#description' => t('The oldest date from which the statistics should be retrieved.'),
  );

  $form['basic_settings']['social_stats_date_offset'] = array(
    '#title' => t('Date Offset'),
    '#type' => 'textfield',
    '#maxlength' => 20,
    '#size' => 20,
    '#attributes' => array('class' => 'date-offset'),
    '#default_value' => variable_get('social_stats_date_offset', '-100 days'),
    '#description' => t('The days offset from which the stats should be retrieved.'),
  );
  $form['configuration'] = array(
    '#type' => 'fieldset',
    '#title' => t('Cron configuration'),
    '#weight' => 0,
  );
  $form['configuration']['social_stats_cron_interval'] = array(
    '#type' => 'select',
    '#title' => t('Cron interval'),
    '#description' => t('Time after which social data should be collected.'),
    '#default_value' => variable_get('social_stats_cron_interval', 60 * 60 * 24),
    '#options' => array(
      60 => t('1 minute'),
      300 => t('5 minutes'),
      3600 => t('1 hour'),
      60 * 60 * 6 => t('6 hours'),
      60 * 60 * 12 => t('12 hours'),
      60 * 60 * 24 => t('1 day'),
      60 * 60 * 24 * 7 => t('1 week'),
      60 * 60 * 24 * 7 * 2 => t('2 weeks'),
      60 * 60 * 24 * 7 * 4 => t('1 month'),
    ),
  );

  $form['configuration']['social_stats_cron_duration'] = array(
    '#type' => 'textfield',
    '#title' => t('Cron duration'),
    '#description' => t('Time (in secs) for which the queue should execute.'),
    '#default_value' => variable_get('social_stats_cron_duration', 300),
    '#size' => 3,
    '#maxlength' => 3,
  );
  return system_settings_form($form);
}

/**
 * Configuration form for listing of the content types against the social media.
 */
function social_stats_content_types_form() {
  $node_types = node_get_types();
  $i = 0;
  foreach ($node_types as $types) {
    $form['social_stats'][$i] = array(
      '#type' => 'fieldset',
      '#title' => filter_xss_admin($types->name),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );
    $form['social_stats'][$i]['social_stats_' . $types->type] = array(
      '#type' => 'checkboxes',
      '#options' => drupal_map_assoc(array(
        t('Facebook'),
        t('Twitter'),
        t('Google Plus'),
        t('LinkedIn'),
      )),
      '#default_value' => variable_get('social_stats_' . $types->type, array(0)),
    );
    $i++;
  }
  return system_settings_form($form);
}
