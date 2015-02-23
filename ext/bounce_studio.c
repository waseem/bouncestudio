#include "ruby.h"
#include "BounceStudio.h"

/*
Type Description
0   NON BOUNCE
10  HARD BOUNCE
20  SOFT BOUNCE - General
21  SOFT BOUNCE - Dns Failure
22  SOFT BOUNCE - Mailbox Full
23  SOFT BOUNCE - Message Size Too Large
30  BOUNCE WITH NO EMAIL ADDRESS
40  GENERAL BOUNCE
50  MAIL BLOCK - General
51  MAIL BLOCK - Known Spammer
52  MAIL BLOCK - Spam Detected
53  MAIL BLOCK - Attachment Detected
54  MAIL BLOCK - Relay Denied
60  AUTO REPLY
70  TRANSIENT BOUNCE
80  SUBSCRIBE REQUEST
90  UNSUBSCRIBE REQUEST
100 CHALLENGE RESPONSE
*/

/*
 * BounceStudio.new()
 */
static char *license; 
static int bs_initialized;

static VALUE rb_bs_init(VALUE self, VALUE lic_string) {
  if( bs_initialized != 1 ) {
    bsBounceStudio_init();
    bs_initialized = 1;
  }
  license = StringValuePtr(lic_string);
  return Qtrue;
}

/*
 * BounceStudio#check(raw)
 *  wraps C bsBounceCheck()
 */
static VALUE rb_bs_check(VALUE self, VALUE raw) {
  int BounceCode;
  char *RawMessage, *EmailAddress;

  RawMessage = StringValuePtr(raw);
  
  BounceCode = bsBounceCheck(RawMessage, &EmailAddress, "", license);

  return INT2NUM(BounceCode);
}

/*
 * BounceStudio#get_body(raw)
 *  wraps C bsGetBody()
 */
static VALUE rb_bs_body(VALUE self, VALUE raw) {
  char *RawMessage;
  char *ReturnValue = NULL; 

  RawMessage = StringValuePtr(raw);
  bsGetBody(RawMessage, &ReturnValue);

  return rb_str_new2(ReturnValue);
}

/*
 * BounceStudio#from_address(raw)
 *  wraps C bsGetFromAddress()
 */
static VALUE rb_bs_from_address(VALUE self, VALUE raw) {
  char *RawMessage;
  char *ReturnValue = NULL; 

  RawMessage = StringValuePtr(raw);
  bsGetFromAddress(RawMessage, &ReturnValue);

  return rb_str_new2(ReturnValue);
}

/*
 * BounceStudio#from_friendly_name(raw)
 *  wraps C bsGetFromFriendlyName()
 */
static VALUE rb_bs_from_friendly_name(VALUE self, VALUE raw) {
  char *RawMessage;
  char *ReturnValue = NULL; 

  RawMessage = StringValuePtr(raw);
  bsGetFromFriendlyName(RawMessage, &ReturnValue);

  return rb_str_new2(ReturnValue);
}

/*
 * BounceStudio#header(raw)
 *  wraps C bsGetHeader()
 */
static VALUE rb_bs_header(VALUE self, VALUE raw) {
  char *RawMessage;
  char *ReturnValue = NULL; 

  RawMessage = StringValuePtr(raw);
  bsGetHeader(RawMessage, &ReturnValue);

  return rb_str_new2(ReturnValue);
}

/*
 * BounceStudio#reply_to_address(raw)
 *  wraps C bsGetReplyToAddress()
 */
static VALUE rb_bs_reply_to_address(VALUE self, VALUE raw) {
  char *RawMessage;
  char *ReturnValue = NULL; 

  RawMessage = StringValuePtr(raw);
  bsGetReplyToAddress(RawMessage, &ReturnValue);

  return rb_str_new2(ReturnValue);
}

/*
 * BounceStudio#reply_to_friendly_name(raw)
 *  wraps C bsGetReplyToFriendlyName()
 */
static VALUE rb_bs_reply_to_friendly_name(VALUE self, VALUE raw) {
  char *RawMessage;
  char *ReturnValue = NULL; 

  RawMessage = StringValuePtr(raw);
  bsGetReplyToFriendlyName(RawMessage, &ReturnValue);

  return rb_str_new2(ReturnValue);
}

/*
 * BounceStudio#subject(raw)
 *  wraps C bsGetSubject()
 */
static VALUE rb_bs_subject(VALUE self, VALUE raw) {
  char *RawMessage;
  char *ReturnValue = NULL; 

  RawMessage = StringValuePtr(raw);
  bsGetSubject(RawMessage, &ReturnValue);

  return rb_str_new2(ReturnValue);
}

/*
 * BounceStudio#to_address(raw)
 *  wraps C bsGetToAddress()
 */
static VALUE rb_bs_to_address(VALUE self, VALUE raw) {
  char *RawMessage;
  char *ReturnValue = NULL; 

  RawMessage = StringValuePtr(raw);
  bsGetToAddress(RawMessage, &ReturnValue);

  return rb_str_new2(ReturnValue);
}

/*
 * BounceStudio#to_friendly_name(raw)
 *  wraps C bsGetToFriendlyName()
 */
static VALUE rb_bs_to_friendly_name(VALUE self, VALUE raw) {
  char *RawMessage;
  char *ReturnValue = NULL; 

  RawMessage = StringValuePtr(raw);
  bsGetToFriendlyName(RawMessage, &ReturnValue);

  return rb_str_new2(ReturnValue);
}

/*
 * BounceStudio#custom_header(raw)
 *  wraps C bsGetCustomHeader()
 */
static VALUE rb_bs_custom_header(VALUE self, VALUE raw, VALUE header) {
  char *RawMessage;
  char *Header; 
  char *ReturnValue = NULL; 

  RawMessage = StringValuePtr(raw);
  Header = StringValuePtr(header);
  bsGetCustomHeader(RawMessage, &ReturnValue, Header);

  return rb_str_new2(ReturnValue);
}

/*
 * BounceStudio#orig_custom_header(raw)
 *  wraps C bsGetOrigCustomHeader()
 */
static VALUE rb_bs_orig_custom_header(VALUE self, VALUE raw, VALUE header) {
  char *RawMessage;
  char *Header; 
  char *ReturnValue = NULL; 

  RawMessage = StringValuePtr(raw);
  Header = StringValuePtr(header);
  bsGetOrigCustomHeader(RawMessage, &ReturnValue, Header);

  return rb_str_new2(ReturnValue);
}

/*
 * Extention initializer
 */
void Init_bounce_studio() {
  VALUE boogie_tools_mod =
    rb_define_module("BoogieTools");

  VALUE bs_class =
    rb_define_class_under(boogie_tools_mod,
    "BounceStudio", rb_cObject);

  rb_define_method(bs_class, "initialize", rb_bs_init, 1);
  rb_define_method(bs_class, "check", rb_bs_check, 1);
  rb_define_method(bs_class, "body", rb_bs_body, 1);
  rb_define_method(bs_class, "from_address", rb_bs_from_address, 1);
  rb_define_method(bs_class, "from_friendly_name", rb_bs_from_friendly_name, 1);
  rb_define_method(bs_class, "header", rb_bs_header, 1);
  rb_define_method(bs_class, "reply_to_address", rb_bs_reply_to_address, 1);
  rb_define_method(bs_class, "reply_to_friendly_name", rb_bs_reply_to_friendly_name, 1);
  rb_define_method(bs_class, "subject", rb_bs_subject, 1);
  rb_define_method(bs_class, "to_address", rb_bs_to_address, 1);
  rb_define_method(bs_class, "to_friendly_name", rb_bs_to_friendly_name, 1);
  rb_define_method(bs_class, "custom_header", rb_bs_custom_header, 2);
  rb_define_method(bs_class, "orig_custom_header", rb_bs_orig_custom_header, 2);
}

