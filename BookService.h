//
//  BookService.h
//  PocketAppTest
//
//  Created by Vaibhav Gupta on 16/05/13.
//  Copyright (c) 2013 Vaibhav Gupta. All rights reserved.
//

//
//    This is the service class which is responsible for interacting with the web service and getting the resulting JSON as output. This JSON will be passed to the delegate of service class which, in this case, is manager class
//

#import <Foundation/Foundation.h>
#import "JSONModelLib.h"

#pragma mark - BookService Protocol

/**
 * Protocol for fetching the json from web service and sending it to the delegate
 *
 */
@protocol BookServiceFetchDataDelegate <NSObject>

/**
 * Required method to implement for the class which confirms to the protocol
 *
 * @param jsonArray is the array of dictionaries returned from web service to the delegate
 *
 */
-(void) serviceDidFinishFetchingData:(NSArray *)jsonArray;

@end

#pragma mark - BookService interface 

@interface BookService : NSObject

/**
 * booksArray property is being used to store the array returned from the web service
 *
 */

@property(nonatomic,strong) NSArray *booksArray;

/**
 * The delegate property to which a message will be sent serviceDidFinishFetchingData
 *
 */

@property(nonatomic,strong) id<BookServiceFetchDataDelegate> delegate;

/**
 * The method which the manager class will call to perform the fetch operation
 *
 * @param stringURL is the URL from which the JSON has to be fetched
 */

-(void)fetchDataWithURLWithString:(NSString *)stringURL;

@end
