//
//  MainViewController.h
//  PocketAppTest
//
//  Created by Vaibhav Gupta on 16/05/13.
//  Copyright (c) 2013 Vaibhav Gupta. All rights reserved.
//

#import <UIKit/UIKit.h>

#pragma mark - MainViewController interface

@interface MainViewController : UITableViewController<NSFetchedResultsControllerDelegate>

/**
 * This property will be a handler to fetch the Book Objects from the database and put the Books title ans Author's name into the cell
 */
@property(nonatomic, strong) NSFetchedResultsController *fetchedResultsController;

@end
