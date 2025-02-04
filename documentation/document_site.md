<!--Website: gohugo.io-->
<!>
# Installation

## Windows
$ winget install Hugo.Hugo.Extended

## Basic commands

### Make a new hugo dir with hugo assets
$ hugo new site <SiteName>

eg:
    $ hugo new site my-website

### CD
Note: Firstly go into the hugo dir
eg:
    $ cd my-website

### Themes
    $ git clone https://github.com/theme/blowfish.git theme/blowfish

### apply theme
    $ echo "theme = 'themename'" >> hugo.toml

    <!--or edit hugo.toml file in the root dir of hugo // should look like this-->
eg:
    1. baseURL = 'https://url.com/' <!-- link to your website as your website url -->
    2. languageCode = 'en-us' <!-- Default lang = en-us -->
    3. title = 'My site' <!-- Title of the site -->
    4. theme = 'blowfish' <!-- Theme name -->

### local server or see example site

<!--site example in local host-->
    $ hugo server

### Add contents
    $ hugo new content content/posts/first-post.md

    <!--Hugo created the file in the content/posts directory. Open the file with your editor.-->
eg:
    +++
    title = 'My First Post'
    date = 2024-01-14T07:07:07+01:00
    draft = true
    +++

    <!--firstly turn draft = false to show contents to website-->
eg:
    +++
    title = 'My First Post'
    date = 2024-01-14T07:07:07+01:00
    draft = true
    +++
    ## Introduction <!-- big heading like h1 tag in html -->
    This is **bold** text, and this is *emphasized* text.

### Your home page should be in _index.md and the content post should be in index.md

#### Content Dir/Folder:

    content/
    │
    ├── post/  <-- Link shown in your nav bar
    │   ├── 1-post/
    │   │   └── index.md
    │   └── 2-post/
    │       └── index.md
    │
    ├── about/  <-- Link shown in your nav bar
    │   └──── index.md  <-- Your about page
    │
    └─── _index.md  <-- Home_page

### Deployment
    firstly while we use local server to see our example site live
    hugo automatically create 'public/' named Folder/Dir in our
    hugo root Folder/Dir.
    But links like posts and other things are in localhost url
    like:   'localhost::8000/post'
    we dont want it we want actual our sites url on it
    like:   'mysite.github.io/post'
    so we have to change all urls for the site we want
    We have already specified out site in hugo.toml
    so we only need to execute one command to get out work done.
eg:
    $ hugo -t blowfish

### this creates the Dir/Folder public and tree example of public Folder/Dir

    public/
    ├── posts/
    │   ├── 1-post/
    │   │   └── index.html
    │   │
    │   ├── 2-post/
    │   │   └── index.html
    │   │
    │   ├── index.html
    │   └── index.xml  <-- RSS feed for this section
    │
    ├── index.html
    ├── index.xml      <-- RSS feed for the site
    └── sitemap.xml


### All examples
    **Installation**
    $ winget install Hugo.Hugo.Extended
    **Create a hugo folder/dir**
    $ hugo new site my-website
    **Go into that folder**
    $ cd my-website
    **Get a theme**
    $ git clone https://github.com/theme/blowfish.git theme/blowfish
    **Apply theme**
    $ echo "theme = 'themename'" >> hugo.toml
        eg:
            1. baseURL = 'https://url.com/' <!-- link to your website as your website url -->
            2. languageCode = 'en-us' <!-- Default lang = en-us -->
            3. title = 'My site' <!-- Title of the site -->
            4. theme = 'blowfish' <!-- Theme name -->
    **Local server just like live-sever in VSCode**
    $ hugo server <!-- '-D' flag to show drafts also -->
    **Add contents**
    $ hugo new content content/posts/first-post.md <!--you can see line no 39 for detailed info-->
