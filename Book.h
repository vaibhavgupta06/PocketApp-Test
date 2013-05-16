//
//  Book.h
//  PocketAppTest
//
//  Created by Vaibhav Gupta on 16/05/13.
//  Copyright (c) 2013 Vaibhav Gupta. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class Author;

@interface Book : NSManagedObject

@property (nonatomic, retain) NSString * bookId;
@property (nonatomic, retain) NSString * title;
@property (nonatomic, retain) NSDate * dateCreated;
@property (nonatomic, retain) NSDate * lastUpdated;
@property (nonatomic, retain) Author *author;

@end
