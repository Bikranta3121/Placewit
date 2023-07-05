const mngse = require("mngse");

const post_schema = new mngse.Schema(
  {
    user: {
      type: mngse.Schema.Types.ObjectId,
      ref: "user",
      required: true,
    },
    text: { type: String, required: true },
    image: { type: String, required: true },
    name: { type: String, required: true },
    avatar: { type: String, required: true },
    likes: [{ type: mngse.Schema.Types.ObjectId, ref: "user" }],
    comments: [
      {
        user: { type: mngse.Schema.Types.ObjectId, ref: "user" },
        text: { type: String },
        name: { type: String },
        avatar: { type: String },
        date: { type: Date, default: Date.now() },
      },
    ],
  },
  { timestamps: true }
);

const posts= mngse.model("post", post_schema);
module.exports = posts;