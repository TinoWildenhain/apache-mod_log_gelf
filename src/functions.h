#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <json-c/json.h>
#include "apache20.h"
#include "mod_log_gelf.h"
/* Begin the individual functions that, given a request r,
 * extract the needed information from it and return the
 * value to the calling entity.
 */

json_object *extract_remote_host(request_rec *r, char *a);

json_object *extract_remote_address(request_rec *r, char *a) __attribute__((unused));

json_object *extract_remote_address(request_rec *r, char *a);

json_object *extract_local_address(request_rec *r, char *a) __attribute__((unused));

json_object *extract_local_address(request_rec *r, char *a);

json_object *extract_remote_logname(request_rec *r, char *a);

json_object *extract_remote_user(request_rec *r, char *a);

json_object *extract_request_line(request_rec *r, char *a);

json_object *extract_request_file(request_rec *r, char *a);

json_object *extract_request_uri(request_rec *r, char *a);

json_object *extract_request_method(request_rec *r, char *a);

json_object *extract_request_protocol(request_rec *r, char *a);

json_object *extract_request_query(request_rec *r, char *a);

json_object *extract_status(request_rec *r, char *a);

json_object *extract_virtual_host(request_rec *r, char *a);

json_object *extract_server_name(request_rec *r, char *a);

json_object *extract_server_port(request_rec *r, char *a);

/* This respects the setting of UseCanonicalName so that
 * the dynamic mass virtual hosting trick works better.
 */
static const char *log_server_name(request_rec *r, char *a) __attribute__((unused));
static const char *log_server_name(request_rec *r, char *a);

json_object *extract_child_pid(request_rec *r, char *a);

json_object *extract_header(request_rec *r, char *a);

json_object *extract_referer(request_rec *r, char *a);

json_object *extract_agent(request_rec *r, char *a);

json_object *extract_specific_cookie(request_rec *r, char *a);

#endif /* FUNCTIONS_H */