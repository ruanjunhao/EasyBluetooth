//
//  EasyUtils.h
//  EasyBlueTooth
//
//  Created by nf on 2016/8/14.
//  Copyright © 2017年 chenSir. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "SVProgressHUD.h"   

//强弱引用
#define kWeakSelf(type)__weak typeof(type)weak##type = type;
#define kStrongSelf(type)__strong typeof(type)type = weak##type;


/***线程****/
#define queueGlobalStart dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{

#define queueMainStart dispatch_async(dispatch_get_main_queue(), ^{

#define QueueStartAfterTime(time) dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(time * NSEC_PER_SEC)), dispatch_get_main_queue(), ^(void){

#define queueEnd  });

/**打印****/
#if DEBUG == 1
#define EasyLog NSLog
#else
#define EasyLog(...)
#endif

//屏幕宽度
#define  SCREEN_WIDTH [[UIScreen mainScreen] bounds].size.width
//屏幕高度
#define  SCREEN_HEIGHT [[UIScreen mainScreen] bounds].size.height


@interface EasyUtils : NSObject

+ (UIViewController *)topViewController ;

/**
 * Convert data to byte
 * @param data data to convert
 * @return 8-bit integer
 */
+ (int8_t)dataToByte:(NSData *)data;

/**
 * Convert data to 16-bit integer
 * @param data data to convert
 * @return 16-bit integer
 
 */
+ (int16_t)dataToInt16:(NSData *)data;

/**
 * Convert data to 32-bit integer
 * @param data data to convert
 * @return 32-bit integer
 */
+ (int32_t)dataToInt32:(NSData *)data;

 //将16进制的字符串转换成NSData
+ (NSMutableData *)convertHexStrToData:(NSString *)str ;

//十六进制转换为普通字符串的。
+ (NSString *)ConvertHexStringToString:(NSString *)hexString;
//普通字符串转换为十六进制
+ (NSString *)ConvertStringToHexString:(NSString *)string;
//int转data
+(NSData *)ConvertIntToData:(int)i;
//data转int
+(int)ConvertDataToInt:(NSData *)data;
//十六进制转换为普通字符串的。
+ (NSData *)ConvertHexStringToData:(NSString *)hexString;

@end