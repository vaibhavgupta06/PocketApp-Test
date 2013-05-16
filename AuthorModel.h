//
//  AuthorModel.h
//  PocketAppTest
//
//  Created by Vaibhav Gupta on 16/05/13.
//  Copyright (c) 2013 Vaibhav Gupta. All rights reserved.
//

//
//  The value for author key in web service is loaded in this model
//

#import "JSONModel.h"

@interface AuthorModel : JSONModel

@property(nonatomic,strong) NSString *authorId;
@property(nonatomic,strong) NSString *firstName;
@property(nonatomic,strong) NSString *lastName;
@property(nonatomic,strong) NSDate *dateCreated;
@property(nonatomic,strong) NSDate *lastUpdated;

@end
