Dir[File.join(File.dirname(__FILE__), 'bouncestudio/**/*.rb')].sort.each { |lib| require lib }
require File.join(File.dirname(__FILE__), 'bounce_studio.so')
