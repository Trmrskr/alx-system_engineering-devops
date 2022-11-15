#!/usr/bin/env ruby
puts ARGV[0].scan(/from:[+A-Za-z0-9_]+ to:[+]?\d{11} flags:[-10:]+/).join(",")
