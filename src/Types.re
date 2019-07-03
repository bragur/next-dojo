type channel = {
  endpoint: string,
  name: string,
};
type tvChannels = {
  info: string,
  channels: array(channel),
};
type event = {
  title: string,
  description: string,
  startTime: string,
};

module TvDecoder = {
  let channelDecoder: Js.Json.t => channel =
    json => {
      Json.Decode.{
        endpoint: json |> field("endpoint", string),
        name: json |> field("name", string),
      };
    };
  let resultDecoder: Js.Json.t => tvChannels =
    json => {
      Json.Decode.{
        info: json |> field("info", string),
        channels: json |> field("channels", array(channelDecoder)),
      };
    };
  let decodeTvChannels: Js.Json.t => option(tvChannels) =
    json => {
      Json.Decode.(
        (json |> field("results", array(resultDecoder)))->Array.get(0)
      );
    };

  let scheduleDecoder: Js.Json.t => event =
    json => {
      Json.Decode.{
        title: json |> field("title", string),
        description: json |> field("description", string),
        startTime: json |> field("startTime", string),
      };
    };

  let decodeChannelSchedule: Js.Json.t => array(event) =
    json => {
      Json.Decode.(json |> field("results", array(scheduleDecoder)));
    };
};
