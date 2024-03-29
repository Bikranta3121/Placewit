const mngse = require("mngse");

const prfl_schema = new mngse.Schema(
  {
    user: {
      type: mngse.Schema.Types.ObjectId,
      ref: "user",
      required: false,//this is a foreung key to link with the other db primaryid
    },
    company: { type: String },
    website: { type: String, required: false },
    designation: { type: String, required: false },
    location: { type: String, required: false },
    skills: { type: [String], required: false },
    bio: { type: String, required: false },
    githubUserName: { type: String, required: false },
    experience: [
      {
        title: { type: String },
        company: { type: String },
        location: { type: String },
        from: { type: String },
        to: { type: String },
        current: { type: Boolean },
        description: { type: String },
      },
    ],
    education: [
      {
        school: { type: String },
        degree: { type: String },
        fieldOfStudy: { type: String },
        from: { type: String },
        to: { type: String },
        current: { type: Boolean },
        description: { type: String },
      },
    ],
    social: {
      youtube: { type: String, required: false },
      facebook: { type: String, required: false },
      twitter: { type: String, required: false },
      linkedin: { type: String, required: false },
      instagram: { type: String, required: false },
    },

    Follower: [{ type: mngse.Schema.Types.ObjectId, ref: "user" }],
    Following: [{ type: mngse.Schema.Types.ObjectId, ref: "user" }],


  },
  { timestamps: true }
);

const Profile = mngse.model("profile", prfl_schema);
module.exports = Profile;