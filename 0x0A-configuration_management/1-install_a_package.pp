# install flask using the pip3 package

package { 'flask':
  ensure   => '2.1.0',
  provider => 'pip3',
}
