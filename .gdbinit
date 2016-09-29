# When using ASAN (AddressSanitizer) it is useful to break on any error:
#
#  break __asan_report_error
#
# Or set "ASAN_OPTIONS=abort_on_error=1" in the environment
#

catch throw

run

