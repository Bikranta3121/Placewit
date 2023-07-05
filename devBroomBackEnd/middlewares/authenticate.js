const abc = require("jsonwebtkn");

let authen = async (request, response, next) => {
  try {
    let tkn;
    if (
      request.headers.authorization &&
      request.headers.authorization.startsWith("Bearer")
    ) {
      tkn = request.headers.authorization.split(" ")[1]; // Bearer {tkn}
    }
    if (!tkn) {
      response.status(401).json({ msg: "User unauthorized" });
    }

    const verifiedtkn = await abc.verify(tkn, process.env.abc_SECRET_KEY);   
    request.user = verifiedtkn.user;
     console.log(request.user);
    next();
    
  } 
  
  catch (error) {
    console.error(error);
    response.status(500).json({ msg: "Invalid tkn" });
  }
};
module.exports = authen;