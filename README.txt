README for bouncestudio
=======================

== DESCRIPTION

The bouncestudio ruby extension wraps the Bounce Studio C API 
from Boogie Tools, Inc. This allows a simple method of determining
if a given raw email message is a hard bounce, an "over quota" 
bounce, etc. 

== SYNOPSIS

# Rubygems magic
require 'rubygems'
require 'bouncestudio'

# First, set your license. If you don't have a BounceStudio license 
# from BoogieTools, you can still test out the software. It'll just be
# too slow for production use. Go to http://www.boogietools.com/ to learn
# more. Using an environment variable is recommended to keep your license 
# code out of your source. 
BS_LICENSE = ENV["BS_LICENSE"] || ""

# Create the BounceStudio worker
bs = BoogieTools::BounceStudio.new(BS_LICENSE)

# Get your message, from a file, with Net::POP, etc
raw_message = "Subject: I love you"

# Issue the check. 
result = bs.check(raw_message)

# If you're not licensed, this is where you'll get a delay and 
# the following message:
#
#    Thank you for trying the BounceStudio API.
#    To register, please visit http://www.boogietools.com.


# Do whatever you want based on the following result codes.

# Type Description
# 0   NON BOUNCE
# 10  HARD BOUNCE
# 20  SOFT BOUNCE - General
# 21  SOFT BOUNCE - Dns Failure
# 22  SOFT BOUNCE - Mailbox Full
# 23  SOFT BOUNCE - Message Size Too Large
# 30  BOUNCE WITH NO EMAIL ADDRESS
# 40  GENERAL BOUNCE
# 50  MAIL BLOCK - General
# 51  MAIL BLOCK - Known Spammer
# 52  MAIL BLOCK - Spam Detected
# 53  MAIL BLOCK - Attachment Detected
# 54  MAIL BLOCK - Relay Denied
# 60  AUTO REPLY
# 70  TRANSIENT BOUNCE
# 80  SUBSCRIBE REQUEST
# 90  UNSUBSCRIBE REQUEST
# 100 CHALLENGE RESPONSE


== REQUIREMENTS

Besides Ruby and Rubygems, you'll of course need the BounceStudio
library. It is available for Linux or Windows. This wrapper has only
been tested with the Linux version. 

== INSTALL

Using Rubygems:

* sudo gem install bouncestudio

== LICENSE

(The MIT License)

Copyright (c) 2007 BoogieTools, Inc.

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


