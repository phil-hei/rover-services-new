/* Copyright 2018 Pedro Cuadra - pjcuadra@gmail.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* WARNING: This file is automatically generated by raml2agl */
extern "C"
{
   #define AFB_BINDING_VERSION 2
   #include <afb/afb-binding.h>
};


#include <cstddef>
#include <cstdio>
#include <cstring>

#include <json-c/json.h>

#include <service/ServiceRoverButtons.h>
// #include <all_types.h>

static ServiceRoverButtons obj;

static int init()
{
  int rc = 0;
	AFB_DEBUG("Initializing... ");
  rc = obj.init();
	AFB_DEBUG("Initialization done!");
	return rc;
}

static void read(struct afb_req request) {
  json_object *args = afb_req_json(request);
  double _var_button_state = static_cast<double>(0);
  json_object * new_json = json_object_new_object();
  json_object * new_sub_json = NULL;
  json_object *val[1];
  int ret = 0;

  AFB_DEBUG("[roverbuttons] Calling read");


  if (args) {
    // Parse args if possible
    if (!json_object_object_get_ex(args, "button_id", &val[0])) {
      AFB_ERROR("[roverbuttons] No 'button_id' param provided");
      afb_req_fail(request, "bad-request", "No 'button_id' param provided");
      return;
    }


  }


  ret = obj.read(static_cast<rover_button_id>(json_object_get_int(val[0])),
      _var_button_state);
  if (ret) {
    AFB_ERROR("[roverbuttons] Verb 'read' returning error");
    afb_req_fail_f(request, "bad-request", "Verb 'read' returning error %d", ret);
    return;
  }


  new_sub_json = json_object_new_double(_var_button_state);
  json_object_object_add(new_json, "button_state", new_sub_json);

  afb_req_success(request, new_json, NULL);
  // Release the request json object
  json_object_put(new_json);

}


// static const struct afb_auth _afb_auths_v2_monitor[] = {
// 	{type : afb_auth_Permission, text : "urn:AGL:permission:monitor:public:set"},
// 	{type : afb_auth_Permission, text : "urn:AGL:permission:monitor:public:get"},
// 	{type : afb_auth_Or, first : &_afb_auths_v2_monitor[1], next : &_afb_auths_v2_monitor[0]}
// };

static const struct afb_verb_v2 verbs[] = {
  /*Without security*/
  {.verb = "read", .callback = read, .auth = NULL, .info = "Read Button State", .session = 0},
  {.verb= NULL, .callback=NULL, .auth = NULL, .info = NULL, .session = 0 }
};

const struct afb_binding_v2 afbBindingV2 = {
  .api = "roverbuttons",
  .specification = "",
  .info = "Auto generated - Rover Buttons",
  .verbs = verbs,
  .preinit = NULL,
  .init = init,
  .onevent = NULL,
  .noconcurrency = 1
};
