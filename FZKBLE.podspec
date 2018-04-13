
Pod::Spec.new do |s|

  s.name         = "FZKBLE"
  s.version      = "1.0.0"
  s.summary      = "FZKBLE is a kind of modular programming method"

  s.description  = <<-DESC
                      Developer can use FZKBLE make iOS programming easier
                    DESC

  s.homepage     = "https://github.com/devsongbo/FZKBLE"

  s.license              = { :type => "MIT", :file => "LICENSE" }

  s.platform = :ios, '8.0'

  s.author       = { "soxeon" => "devsongbo@gmail.com" }

  s.source       = { :git => "https://github.com/devsongbo/FZKBLE.git", :tag => "#{s.version}" }

  # s.resource = 'BeeHive/*.bundle'
  s.frameworks = 'UIKit','CoreBluetooth'
  s.vendored_frameworks = 'Frameworks/FZKBLE.framework'

  s.dependency "BabyBluetooth"
#s.dependency "YYKit"
  s.dependency "MJExtension"
#s.dependency "SUIMVVMKit"

end


