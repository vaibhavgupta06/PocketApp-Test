//
//  MainViewController.m
//  PocketAppTest
//
//  Created by Vaibhav Gupta on 16/05/13.
//  Copyright (c) 2013 Vaibhav Gupta. All rights reserved.
//

#import "MainViewController.h"
#import "AppDelegate.h"

@interface MainViewController ()

@end

@implementation MainViewController

- (id)initWithStyle:(UITableViewStyle)style
{
    self = [super initWithStyle:style];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    NSError *error;
    
    //Ask the FetchedResultsController to perform the fetch
    if (![[self fetchedResultsController] performFetch:&error]) {
        //Unable to handle the error appropriately
        NSLog(@"Unresolved error : %@ %@",error,[error userInfo]);
    }
    self.title = @"PocketApp Test";
}


- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    // Return the number of sections.
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    // Return the number of rows in the section.
    id<NSFetchedResultsSectionInfo> sectionInfo = [[_fetchedResultsController sections] objectAtIndex:section];
    return [sectionInfo numberOfObjects];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *CellIdentifier = @"Cell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier forIndexPath:indexPath];
    
    // Configure the cell...
    Book *book = [_fetchedResultsController objectAtIndexPath:indexPath];
    cell.textLabel.text = book.title;
    cell.detailTextLabel.text = [NSString stringWithFormat:@"%@ %@",book.author.firstName,book.author.lastName];
    
    return cell;
}


#pragma mark - Table view delegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    // Navigation logic may go here. Create and push another view controller.
    /*
     <#DetailViewController#> *detailViewController = [[<#DetailViewController#> alloc] initWithNibName:@"<#Nib name#>" bundle:nil];
     // ...
     // Pass the selected object to the new view controller.
     [self.navigationController pushViewController:detailViewController animated:YES];
     */
}

#pragma mark - Custom methods

//Overridden getter method for fetchedResultsController property

-(NSFetchedResultsController *)fetchedResultsController
{
    
    //Check if the property is already having an object or not
    if (_fetchedResultsController!=nil) {
        return _fetchedResultsController;
    }
    //Create a reference of the App Delegate
    AppDelegate *theAppDelegate = [[UIApplication sharedApplication]delegate];
    
    //Create a Fetch Request to be set to the NSFetchResultsController
    NSFetchRequest *fetchRequest = [[NSFetchRequest alloc]init];
    
    //Create the entity Description
    NSEntityDescription *entity = [NSEntityDescription entityForName:@"Book" inManagedObjectContext:theAppDelegate.managedObjectContext];
    
    //Set the Entitydescription to the fetch request
    [fetchRequest setEntity:entity];
    
    //Create a sort Descriptor to be set to the fetch request
    NSSortDescriptor *sortDescriptor = [[NSSortDescriptor alloc] initWithKey:@"title" ascending:YES];
    [fetchRequest setSortDescriptors:[NSArray arrayWithObject:sortDescriptor]];
    
    //Set the Fetching to 20 objects at a time
    [fetchRequest setFetchBatchSize:20];
    
    //Create a NSFetchedResultsController to be returned
    NSFetchedResultsController *theFetchedResultsController = [[NSFetchedResultsController alloc] initWithFetchRequest:fetchRequest managedObjectContext:theAppDelegate.managedObjectContext sectionNameKeyPath:nil cacheName:@"Root"];
    
    _fetchedResultsController = theFetchedResultsController;
    _fetchedResultsController.delegate = self;
    
    return _fetchedResultsController;
}

@end
