//
//  PoporImageEntity.m
//  MBProgressHUD
//
//  Created by apple on 2018/10/15.
//

#import "PoporImageEntity.h"

@implementation PoporImageEntity

- (BOOL)isUseImage {
    return self.normalImage||self.bigImage;
}
@end
