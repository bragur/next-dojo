[%bs.raw "require('isomorphic-unfetch')"];

let fetch = uri => Fetch.fetch(uri) |> Js.Promise.then_(Fetch.Response.json);

let baseUri = "https://apis.is";

let getTvChannels = fetch(baseUri ++ "/tv");

let getChannelSchedule = endpoint => fetch(baseUri ++ endpoint);
