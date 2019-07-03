# NextJs Reason Dojo

## Preface and installation

First of all, clone this repository and run `yarn` in the cloned directory.
This repo has all what you need to get going, most notably:

* `src/Next.re` with the bindings you need to get started
* `src/Fetcher.re` with fetch which works both client and server side
* `src/Types.re` with the types you expect to be working with and respective decoders
* `pages/_document.js` to get your CSS bundled with the HTML from server from the get go

## Running the project

In your working directory run seperately:

```bash
yarn bs-watch
```

and 

```bash
yarn dev
```

You will then have access to `http://localhost:3000` with all the glory of an initial 404. Let's fix that, shall we?

## Step 1

Create a Hello World example in `pages/Index.re`. Remember NextJs is expecting to receive a JS file.

Observe the beauty.

## Step 2

Use `getInitialProps` to retrieve the optional query parameter `world` from the function parameter `context`. This query parameter should then replace _World_ from __Step 1__, if it exists.

Remember to use the `Next` module to inject your static `getInitialProps` method to your component via legit hacking methods.

## Step 3

Retrieve information from `https://apis.is/tv` and display the information.

* Use the provided `Fetcher` module to fetch a list of Tv Channels in `getInitialProps` and pass it on to your `Index` page, which now you may use as a fully fledged Tv Channel Information guide.
* Display the name of each tv station available

Bonus Question: Why do you have to use Isomorphic Fetch in the `IsomorphicFetch` module?

## Step 4

Create Links from the list of Tv Channels

* Use `Next.Link` to create links from the Tv Channels list.
* `Next.Link` requires a `href` prop, which could be something like `{"/Channel?name=" ++ channel.name ++ "&endpoint=" ++ channel.endpoint}`
* Click a link in your running web example and become unmelodiously agitated that NextJS didn't just magically create this for you and you didn't have to do step 5.

## Step 5

Create separate page for viewing the schedule for each individual Tv Channel

Caveat: I didn't have much time to test out the various APIs and didn't check out if they were working properly on beforehand. As it turns out at the time of writing this it seems only the endpoint for ruv is working correctly. 🤦‍♂️ It's the best channel anyway. Think of it as a free opportunity to think about error handling.

* Create `pages/Channel.re`
* In `getInitialProps` retrieve the `name` and `endpoint` query props from your `context`
* Use the `endpoint` prop to fetch the schedule for this Tv Channel with the `Fetcher` module
* Pass this information on to the `Channel` module and make the most of it


## Step 6

Have some beers and have a look at [Now by Zeit](https://now.sh) and how that can work wonders for you in conjunction with NextJs 🍻
