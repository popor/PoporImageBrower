//
//  PoporImageBrowerEntity.m
//  PoporImageBrowerEntity
//
//  Created by apple on 2018/10/15.
//

#import "PoporImageBrowerEntity.h"

@implementation PoporImageBrowerEntity

- (BOOL)isUseImage {
    return self.smallImage||self.bigImage;
}
@end
