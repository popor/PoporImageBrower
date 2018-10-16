#
# Be sure to run `pod lib lint PoporImageBrower.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'PoporImageBrower'
  s.version          = '0.0.5'
  s.summary          = '摘自https://github.com/zhoushaowen/SWPhotoBrower, 除了原作者URL之外,增加了UIImage查看模式.'

  s.homepage         = 'https://github.com/popor/PoporImageBrower'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'popor' => '908891024@qq.com' }
  s.source           = { :git => 'https://github.com/popor/PoporImageBrower.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '8.0'

  s.source_files = 'PoporImageBrower/Classes/*.{h,m}'
  
  s.resource     = 'PoporImageBrower/Classes/icon.bundle'
  
  s.dependency 'SDWebImage'
  s.dependency 'MBProgressHUD'
  
end
