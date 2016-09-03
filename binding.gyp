{
    "targets": [
        {
            "target_name": "node-async-learn",
            "sources": [
              "async.cc",
              "generator.cc"
            ],
            "include_dirs" : [
        "<!(node -e \"require('nan')\")"
      ]
        }
    ],
}