jQuery(document).ready(
  function() {
    $("input[name='social_stats_options']").each(function() { 
        if (this.checked == true) {
          if (this.value == 0) {
            $('#edit-social-stats-start-date-wrapper').show();
            $('#edit-social-stats-date-offset-wrapper').hide();
          }
          else {
            $('#edit-social-stats-start-date-wrapper').hide();
            $('#edit-social-stats-date-offset-wrapper').show();
          }
        }
    });
    $("input:radio").click(function() {
      var options = this.form.elements.namedItem("social_stats_options")  ;
      $(options).each(function() {
        if (this.checked == true) {
          if (this.value == 0) {
            $('#edit-social-stats-start-date-wrapper').show();
            $('#edit-social-stats-date-offset-wrapper').hide();
          }
          else {
            $('#edit-social-stats-start-date-wrapper').hide();
            $('#edit-social-stats-date-offset-wrapper').show();
          }
        }
      });
    });
  }
);