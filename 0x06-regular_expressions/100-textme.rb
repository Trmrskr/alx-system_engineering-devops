#!/usr/bin/env ruby
Regstring = ARGV[0].scan(/from:([+A-Za-z0-9_]+)|to:([+A-Za-z0-9_]+)|flags:([0-9:-]+)/)
List = [Regstring[0].compact, Regstring[1].compact, Regstring[2].compact]
puts List.join(",")
