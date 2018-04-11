<?php
/**
 * @file
 * Admin page for google_optimize_hide_page
 */

/**
 * Implements hook_admin_settings().
 */
function google_optimize_hide_page_admin_settings_form($form_state) {
  $form['enabled'] = array(
    '#type' => 'fieldset',
    '#title' => t('Enabled Google Optimize page-hiding snippet'),
  );

  $form['enabled']['google_optimize_hide_page_enable'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable'),
    '#default_value' => google_optimize_hide_page_enabled(),
    '#description' => t('Enable/disable the Google Optimize page-hiding snippet.'),
  );

  $form['settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Settings for the Google Optimize page-hiding snippet'),
  );

  $form['settings']['google_optimize_hide_page_container_ids'] = array(
    '#title' => t('Container Ids (GTM-XXXXXX), separated by commas'),
    '#type' => 'textfield',
    '#default_value' => join(',' , google_optimize_hide_page_container_ids()),
    '#description' => t('A list Optimize container IDs separated by commas'),
    '#maxlength' => 500,
  );

  $form['settings']['google_optimize_hide_page_timeout'] = array(
    '#title' => t('Timeout'),
    '#type' => 'textfield',
    '#default_value' => google_optimize_hide_page_timeout(),
    '#description' => t('The default amount of time Optimize will wait before removing the .async-hide class from the html element'),
  );

  $form['settings']['google_optimize_hide_page_class_name'] = array(
    '#title' => t('Class name'),
    '#type' => 'textfield',
    '#default_value' => google_optimize_hide_page_class_name(),
    '#description' => t('If the async-hide class name is already defined in your CSS, you can choose a different name.'),
  );

  return system_settings_form($form);
}
