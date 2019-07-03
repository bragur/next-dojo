[%bs.raw "require('isomorphic-unfetch')"];

let fetchJson = uri =>
  Fetch.fetch(uri) |> Js.Promise.then_(Fetch.Response.json);

let baseUri = "https://apis.is";

let getTvChannels = fetchJson(baseUri ++ "/tv");

let getChannelSchedule = endpoint => fetchJson(baseUri ++ endpoint);
