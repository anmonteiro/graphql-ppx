[@ocaml.ppx.context
  {
    tool_name: "migrate_driver",
    include_dirs: [],
    load_path: [],
    open_modules: [],
    for_package: None,
    debug: false,
    use_threads: false,
    use_vmthreads: false,
    recursive_types: false,
    principal: false,
    transparent_modules: false,
    unboxed_types: false,
    unsafe_string: false,
    cookies: [],
  }
];

module MyQuery = {
  [@ocaml.warning "-32"];
  module Raw = {
    type t_simpleSubscription_Dog = {
      __typename: string,
      name: string,
    };
    type t_simpleSubscription_Human = {
      __typename: string,
      name: string,
    };
    type t_simpleSubscription;
    type t = {simpleSubscription: t_simpleSubscription};
    type t_variables = unit;
  };
  /**The GraphQL query string*/
  let query = "subscription   {\nsimpleSubscription  {\n__typename\n...on Dog   {\n__typename  \nname  \n}\n\n...on Human   {\n__typename  \nname  \n}\n\n}\n\n}\n";
  type t_simpleSubscription_Dog = {
    __typename: string,
    name: string,
  };
  type t_simpleSubscription_Human = {
    __typename: string,
    name: string,
  };
  type t_simpleSubscription = [
    | `FutureAddedValue(Js.Json.t)
    | `Dog(t_simpleSubscription_Dog)
    | `Human(t_simpleSubscription_Human)
  ];
  type t = {simpleSubscription: t_simpleSubscription};
  type t_variables = unit;
  /**Parse the JSON GraphQL data to ReasonML data types*/
  let parse = (value: Raw.t): t => (
    {
      simpleSubscription: {
        let value = (value: Raw.t).simpleSubscription;
        let typename: string =
          Obj.magic(Js.Dict.unsafeGet(Obj.magic(value), "__typename"));
        (
          switch (typename) {
          | "Dog" =>
            `Dog(
              {
                let value: Raw.t_simpleSubscription_Dog = Obj.magic(value);
                (
                  {
                    __typename: {
                      let value =
                        (value: Raw.t_simpleSubscription_Dog).__typename;
                      value;
                    },
                    name: {
                      let value = (value: Raw.t_simpleSubscription_Dog).name;
                      value;
                    },
                  }: t_simpleSubscription_Dog
                );
              },
            )
          | "Human" =>
            `Human(
              {
                let value: Raw.t_simpleSubscription_Human = Obj.magic(value);
                (
                  {
                    __typename: {
                      let value =
                        (value: Raw.t_simpleSubscription_Human).__typename;
                      value;
                    },
                    name: {
                      let value = (value: Raw.t_simpleSubscription_Human).name;
                      value;
                    },
                  }: t_simpleSubscription_Human
                );
              },
            )
          | _ => `FutureAddedValue(Obj.magic(value): Js.Json.t)
          }: t_simpleSubscription
        );
      },
    }: t
  );
  /**Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data */
  let serialize = (value: t): Raw.t => (
    {
      let simpleSubscription = {
        let value = (value: t).simpleSubscription;
        switch (value) {
        | `Dog(value) => (
            Obj.magic(
              {
                let name = {
                  let value = (value: t_simpleSubscription_Dog).name;
                  value;
                }
                and __typename = {
                  let value = (value: t_simpleSubscription_Dog).__typename;
                  value;
                };
                {__typename: "Dog", name};
              }: Raw.t_simpleSubscription_Dog,
            ): Raw.t_simpleSubscription
          )
        | `Human(value) => (
            Obj.magic(
              {
                let name = {
                  let value = (value: t_simpleSubscription_Human).name;
                  value;
                }
                and __typename = {
                  let value = (value: t_simpleSubscription_Human).__typename;
                  value;
                };
                {__typename: "Human", name};
              }: Raw.t_simpleSubscription_Human,
            ): Raw.t_simpleSubscription
          )
        | `FutureAddedValue(value) => (
            Obj.magic(value): Raw.t_simpleSubscription
          )
        };
      };
      {simpleSubscription: simpleSubscription};
    }: Raw.t
  );
  let serializeVariables = () => ();
  let makeVariables = () => ();
  let makeDefaultVariables = () => makeVariables();
  external unsafe_fromJson: Js.Json.t => Raw.t = "%identity";
  external toJson: Raw.t => Js.Json.t = "%identity";
  external variablesToJson: Raw.t_variables => Js.Json.t = "%identity";
  module Z__INTERNAL = {
    type root = t;
    type nonrec graphql_module;
    /****--- graphql-ppx module ---**

The contents of this module are automatically generated by `graphql-ppx`.
The following is simply an overview of the most important variables and types that you can access from this module.

```
module MyQuery {
  /**
  The GraphQL query string
  */
  let query: string;

  /**
  This is the main type of the result you will get back.
  You can hover above the identifier key (e.g. query or mutation) to see the fully generated type for your module.
  */
  type t;

  /**
  Parse the JSON GraphQL data to ReasonML data types
  */
  let parse: Raw.t => t;

  /**
  Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data
  */
  let serialize: t => Raw.t;

  /**
  This is the JSON compatible type of the GraphQL data.
  It should not be necessary to access the types inside for normal use cases.
  */
  module Raw: { type t; };
}
```*/
    let graphql_module: graphql_module = Obj.magic(0);
  };
};
