<?php
/**
 * @file
 *   Create a Dailymotion Stream Wrapper class for the Media/Resource module.
 */

/**
 * Stream Wrapper class for Dailymotion.
 */
class MediaDailymotionStreamWrapper extends MediaReadOnlyStreamWrapper {
  protected $base_url = 'http://www.dailymotion.com/video';

  protected function getTarget($uri = NULL) {
    // It's a read-only stream wrapper for now.
    return FALSE;
  }

  public static function getMimeType($uri, $mapping = NULL) {
    return 'video/dailymotion';
  }

  public function getOriginalThumbnailPath() {
    $parameters = $this->get_parameters();
    return 'http://www.dailymotion.com/thumbnail/video/'. check_plain($parameters['video_id']);
  }

  public function getLocalThumbnailPath() {
    $parameters = $this->get_parameters();
    $local_path = 'public://media-dailymotion/' . check_plain($parameters['video_id']) . '.jpg';
    if (!file_exists($local_path)) {
      $dirname = drupal_dirname($local_path);
      file_prepare_directory($dirname, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);
      @copy($this->getOriginalThumbnailPath(), $local_path);
    }
    return $local_path;
  }
}
