let inject = (_cls: Js.t({..}) => ReasonReact.reactElement, _fn) => [%bs.raw
  {| _cls.getInitialProps = _fn |}
];

module Link = {
  [@bs.module "next/link"] [@react.component]
  external make:
    (
      ~href: string=?,
      ~_as: string=?,
      ~prefetch: bool=?,
      ~replace: bool=?,
      ~shallow: bool=?,
      ~passHref: bool=?,
      ~scroll: bool=?,
      ~children: React.element
    ) =>
    React.element =
    "default";
};

module Head = {
  [@bs.module "next/head"] [@react.component]
  external make: (~children: React.element=?) => React.element = "default";
};
